////////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

import XCTest
import RealmSwift
import Realm
import Realm.Private
import Foundation

private func realmWithCustomSchema(path: String, schema :RLMSchema) -> RLMRealm {
    return RLMRealm(path: path, key: nil, readOnly: false, inMemory: false, dynamic: true, schema: schema, error: nil)!
}

private func realmWithSingleClass(path: String, objectSchema: RLMObjectSchema) -> RLMRealm {
    let schema = RLMSchema()
    schema.objectSchema = [objectSchema]
    return realmWithCustomSchema(path, schema)
}

private func realmWithSingleClassProperties(path: String, className: String, properties: [AnyObject]) -> RLMRealm {
    let objectSchema = RLMObjectSchema(className: className, objectClass: MigrationObject.self, properties: properties)
    return realmWithSingleClass(path, objectSchema)
}

private func dynamicRealm(path: String) -> RLMRealm {
    return RLMRealm(path: path, key: nil, readOnly: false, inMemory: false, dynamic: true, schema: nil, error: nil)
}

class MigrationTests: TestCase {

    // MARK Utility methods

    // create realm at path and test version is 0
    private func createAndTestRealmAtPath(realmPath: String) {
        autoreleasepool {
            Realm(path: realmPath)
            return
        }
        XCTAssertEqual(UInt64(0), schemaVersionAtPath(realmPath)!, "Initial version should be 0")
    }

    // migrate realm at path and ensure migration
    private func migrateAndTestRealm(realmPath: String, shouldRun: Bool = true, schemaVersion: UInt64 = 1, autoMigration: Bool = false, block: MigrationBlock? = nil) {
        var didRun = false
        setSchemaVersion(schemaVersion, realmPath, { migration, oldSchemaVersion in
            if let block = block {
                block(migration: migration, oldSchemaVersion: oldSchemaVersion)
            }
            didRun = true
            return
        })

        if autoMigration {
            Realm(path: realmPath)
        }
        else {
            migrateRealm(realmPath, encryptionKey: nil)
        }

        XCTAssertEqual(didRun, shouldRun)
    }

    // MARK Test cases

    func testSetDefaultRealmSchemaVersion() {
        createAndTestRealmAtPath(Realm.defaultPath)
        var didRun = false
        setDefaultRealmSchemaVersion(1, { migration, oldSchemaVersion in
            didRun = true
            return
        })
        migrateRealm(Realm.defaultPath, encryptionKey: nil)

        XCTAssertEqual(didRun, true)
        XCTAssertEqual(UInt64(1), schemaVersionAtPath(Realm.defaultPath)!)
    }

    func testSetSchemaVersion() {
        createAndTestRealmAtPath(testRealmPath())
        migrateAndTestRealm(testRealmPath())

        XCTAssertEqual(UInt64(1), schemaVersionAtPath(testRealmPath())!)
    }

    func testSchemaVersionAtPath() {
        var error : NSError? = nil
        assertNil(schemaVersionAtPath(Realm.defaultPath, error: &error), "Version should be nil before Realm creation")
        XCTAssertNotNil(error, "Error should be set")

        Realm()
        XCTAssertEqual(UInt64(0), schemaVersionAtPath(Realm.defaultPath)!, "Initial version should be 0")
        assertThrows(schemaVersionAtPath("/dev/null"))
    }

    func testMigrateRealm() {
        createAndTestRealmAtPath(testRealmPath())

        // manually migrate (autoMigration == false)
        migrateAndTestRealm(testRealmPath(), shouldRun: true, autoMigration: false)

        // calling again should be no-op
        migrateAndTestRealm(testRealmPath(), shouldRun: false, autoMigration: false)

        // test auto-migration
        migrateAndTestRealm(testRealmPath(), schemaVersion: 2, shouldRun: true, autoMigration: true)
    }

    func testMigrationProperties() {
        let prop = RLMProperty(name: "stringCol", type: RLMPropertyType.Int, objectClassName: nil, indexed: false, optional: false)
        autoreleasepool { () -> () in
            realmWithSingleClassProperties(Realm.defaultPath, "SwiftStringObject", [prop])
            return
        }

        migrateAndTestRealm(Realm.defaultPath, block: { migration, oldSchemaVersion in
            XCTAssertEqual(migration.oldSchema.objectSchema.count, 1)
            XCTAssertGreaterThan(migration.newSchema.objectSchema.count, 1)
            XCTAssertEqual(migration.oldSchema.objectSchema[0].properties.count, 1)
            XCTAssertEqual(migration.newSchema["SwiftStringObject"]!.properties.count, 1)
            XCTAssertEqual(migration.oldSchema["SwiftStringObject"]!.properties[0].type, PropertyType.Int)
            XCTAssertEqual(migration.newSchema["SwiftStringObject"]!["stringCol"]!.type, PropertyType.String)
        })
    }

    func testEnumerate() {
        autoreleasepool {
            _ = Realm()
        }

        autoreleasepool {
            self.migrateAndTestRealm(Realm.defaultPath, block: { migration, oldSchemaVersion in
                migration.enumerate("SwiftStringObject", { oldObj, newObj in
                    XCTFail("No objects to enumerate")
                })

                migration.enumerate("NoSuchClass", {oldObj, newObj in}) // shouldn't throw
            })
        }

        autoreleasepool {
            // add object
            Realm().write {
                Realm().create(SwiftStringObject.self, value: ["string"])
                return
            }
        }

        autoreleasepool {
            self.migrateAndTestRealm(Realm.defaultPath, schemaVersion: 2, block: { migration, oldSchemaVersion in
                var count = 0
                migration.enumerate("SwiftStringObject", { oldObj, newObj in
                    XCTAssertEqual(newObj!.objectSchema.className, "SwiftStringObject")
                    XCTAssertEqual(oldObj!.objectSchema.className, "SwiftStringObject")
                    XCTAssertEqual(newObj!["stringCol"] as! String, "string")
                    XCTAssertEqual(oldObj!["stringCol"] as! String, "string")
                    self.assertThrows(oldObj!["noSuchCol"] as! String)
                    self.assertThrows(newObj!["noSuchCol"] as! String)
                    count++
                })
                XCTAssertEqual(count, 1)
            })
        }

        autoreleasepool {
            Realm().write {
                Realm().create(SwiftArrayPropertyObject.self, value: ["string", [["array"]], [[2]]])
            }
        }

        autoreleasepool {
            self.migrateAndTestRealm(Realm.defaultPath, schemaVersion: 3, block: { migration, oldSchemaVersion in
                migration.enumerate("SwiftArrayPropertyObject") { oldObject, newObject in
                    XCTAssertTrue(oldObject! as AnyObject is MigrationObject)
                    XCTAssertTrue(newObject! as AnyObject is MigrationObject)
                    XCTAssertTrue(oldObject!["array"]! is List<MigrationObject>)
                    XCTAssertTrue(oldObject!["array"]! is List<MigrationObject>)
                }
            })
        }
    }

    func testCreate() {
        autoreleasepool {
            _ = Realm()
        }

        migrateAndTestRealm(Realm.defaultPath, block: { migration, oldSchemaVersion in
            migration.create("SwiftStringObject", value: ["string"])
            migration.create("SwiftStringObject", value: ["stringCol": "string"])
            migration.create("SwiftStringObject")

            self.assertThrows(migration.create("NoSuchObject", value: []))
        })

        let objects = Realm().objects(SwiftStringObject)
        XCTAssertEqual(objects.count, 3)
        XCTAssertEqual(objects[0].stringCol, "string")
        XCTAssertEqual(objects[1].stringCol, "string")
        XCTAssertEqual(objects[2].stringCol, "")
    }

    func testDelete() {
        autoreleasepool {
            Realm().write {
                Realm().create(SwiftStringObject.self, value: ["string1"])
                Realm().create(SwiftStringObject.self, value: ["string2"])
                return
            }
        }

        self.migrateAndTestRealm(Realm.defaultPath, block: { migration, oldSchemaVersion in
            var deleted = false;
            migration.enumerate("SwiftStringObject", { oldObj, newObj in
                if deleted == false {
                    migration.delete(newObj!)
                    deleted = true
                }
            })
        })

        XCTAssertEqual(Realm().objects(SwiftStringObject).count, 1)
    }

    func testDeleteData() {
        autoreleasepool {
            let realm = realmWithSingleClassProperties(testRealmPath(), "DeletedClass", [])
            realm.transactionWithBlock {
                realm.createObject("DeletedClass", withValue: [])
            }
        }

        autoreleasepool {
            setSchemaVersion(1, testRealmPath()) { migration, oldSchemaVersion in
                XCTAssertEqual(oldSchemaVersion, 0, "Initial schema version should be 0");

                XCTAssertTrue(migration.deleteData("DeletedClass"));
                XCTAssertFalse(migration.deleteData("NoSuchClass"));

                migration.create(SwiftStringObject.className(), value: ["migration"])
                XCTAssertTrue(migration.deleteData(SwiftStringObject.className()));
            }
            migrateRealm(testRealmPath())
        }

        autoreleasepool {
            let realm = dynamicRealm(testRealmPath())
            XCTAssertNil(realm.schema.schemaForClassName("DeletedClass"))
            XCTAssertEqual(0, realm.allObjects("SwiftStringObject").count)
        }
    }

    // test getting/setting all property types
    func testMigrationObject() {
        autoreleasepool {
            Realm().write {
                var object = SwiftObject()
                object.boolCol = true
                object.objectCol = SwiftBoolObject(value: [true])
                object.arrayCol.append(SwiftBoolObject(value: [false]))
                Realm().add(object)
                return
            }
        }

        self.migrateAndTestRealm(Realm.defaultPath, block: { migration, oldSchemaVersion in
            var enumerated = false
            migration.enumerate("SwiftObject", { oldObj, newObj in
                XCTAssertEqual(oldObj!["boolCol"] as! Bool, true)
                XCTAssertEqual(newObj!["boolCol"] as! Bool, true)
                XCTAssertEqual(oldObj!["intCol"] as! Int, 123)
                XCTAssertEqual(newObj!["intCol"] as! Int, 123)
                XCTAssertEqual(oldObj!["floatCol"] as! Float, 1.23 as Float)
                XCTAssertEqual(newObj!["floatCol"] as! Float, 1.23 as Float)
                XCTAssertEqual(oldObj!["doubleCol"] as! Double, 12.3 as Double)
                XCTAssertEqual(newObj!["doubleCol"] as! Double, 12.3 as Double)

                var binaryCol = "a".dataUsingEncoding(NSUTF8StringEncoding)!
                XCTAssertEqual(oldObj!["binaryCol"] as! NSData, binaryCol)
                XCTAssertEqual(newObj!["binaryCol"] as! NSData, binaryCol)

                var dateCol = NSDate(timeIntervalSince1970: 1)
                XCTAssertEqual(oldObj!["dateCol"] as! NSDate, dateCol)
                XCTAssertEqual(newObj!["dateCol"] as! NSDate, dateCol)

                // FIXME - test that casting to SwiftBoolObject throws
                XCTAssertEqual((oldObj!["objectCol"] as! MigrationObject)["boolCol"] as! Bool, true)
                XCTAssertEqual((newObj!["objectCol"] as! MigrationObject)["boolCol"] as! Bool, true)

                XCTAssertEqual((oldObj!["arrayCol"] as! List<MigrationObject>).count, 1)
                XCTAssertEqual((oldObj!["arrayCol"] as! List<MigrationObject>)[0]["boolCol"] as! Bool, false)
                XCTAssertEqual((newObj!["arrayCol"] as! List<MigrationObject>).count, 1)
                XCTAssertEqual((newObj!["arrayCol"] as! List<MigrationObject>)[0]["boolCol"] as! Bool, false)

                // edit all values
                newObj!["boolCol"] = false
                newObj!["intCol"] = 1
                newObj!["floatCol"] = 1.0
                newObj!["doubleCol"] = 10.0
                newObj!["binaryCol"] = NSData(bytes: "b", length: 1)
                newObj!["dateCol"] = NSDate(timeIntervalSince1970: 2)

                let falseObj = SwiftBoolObject(value: [false])
                newObj!["objectCol"] = falseObj

                var list = newObj!["arrayCol"] as! List<MigrationObject>
                list[0]["boolCol"] = true
                list.append(newObj!["objectCol"] as! MigrationObject)

                let trueObj = migration.create(SwiftBoolObject.className(), value: [true])
                list.append(trueObj)

                // verify list property
                list = newObj!["arrayCol"] as! List<MigrationObject>
                XCTAssertEqual(list.count, 3)
                XCTAssertEqual(list[0]["boolCol"] as! Bool, true)
                XCTAssertEqual(list[1]["boolCol"] as! Bool, false)
                XCTAssertEqual(list[2]["boolCol"] as! Bool, true)

                self.assertThrows(newObj!.valueForKey("noSuchKey"))
                self.assertThrows(newObj!.setValue(1, forKey: "noSuchKey"))

                // set it again
                newObj!["arrayCol"] = [falseObj, trueObj]

                enumerated = true
            })
            XCTAssertEqual(enumerated, true)
        })

        // refresh to update realm
        Realm().refresh()

        // check edited values
        let object = Realm().objects(SwiftObject).first!
        XCTAssertEqual(object.boolCol, false)
        XCTAssertEqual(object.intCol, 1)
        XCTAssertEqual(object.floatCol, 1.0 as Float)
        XCTAssertEqual(object.doubleCol, 10.0)
        XCTAssertEqual(object.binaryCol, NSData(bytes: "b", length: 1))
        XCTAssertEqual(object.dateCol, NSDate(timeIntervalSince1970: 2))
        XCTAssertEqual(object.objectCol.boolCol, false)
        XCTAssertEqual(object.arrayCol.count, 2)
        XCTAssertEqual(object.arrayCol[0].boolCol, false)
        XCTAssertEqual(object.arrayCol[1].boolCol, true)

        // make sure we added new bool objects as object property and in the list
        XCTAssertEqual(Realm().objects(SwiftBoolObject).count, 4)
    }
}

