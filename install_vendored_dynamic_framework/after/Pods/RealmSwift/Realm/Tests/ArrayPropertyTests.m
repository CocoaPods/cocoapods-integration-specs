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

#import "RLMTestCase.h"

@implementation DogArrayObject
@end

@interface ArrayPropertyTests : RLMTestCase
@end

@implementation ArrayPropertyTests

-(void)testPopulateEmptyArray {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *array = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[], @[]]];
    XCTAssertNotNil(array.array, @"Should be able to get an empty array");
    XCTAssertEqual(array.array.count, 0U, @"Should start with no array elements");

    StringObject *obj = [[StringObject alloc] init];
    obj.stringCol = @"a";
    [array.array addObject:obj];
    [array.array addObject:[StringObject createInRealm:realm withValue:@[@"b"]]];
    [array.array addObject:obj];
    [realm commitWriteTransaction];

    XCTAssertEqual(array.array.count, 3U, @"Should have three elements in array");
    XCTAssertEqualObjects([array.array[0] stringCol], @"a", @"First element should have property value 'a'");
    XCTAssertEqualObjects([array.array[1] stringCol], @"b", @"Second element should have property value 'b'");
    XCTAssertEqualObjects([array.array[2] stringCol], @"a", @"Third element should have property value 'a'");

    RLMArray *arrayProp = array.array;
    XCTAssertThrows([arrayProp addObject:obj], @"Adding array object outside a transaction should throw");

    // make sure we can fast enumerate
    for (RLMObject *obj in array.array) {
        XCTAssertTrue(obj.description.length, @"Object should have description");
    }
}

-(void)testModifyDetatchedArray {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *arObj = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[], @[]]];
    XCTAssertNotNil(arObj.array, @"Should be able to get an empty array");
    XCTAssertEqual(arObj.array.count, 0U, @"Should start with no array elements");

    StringObject *obj = [[StringObject alloc] init];
    obj.stringCol = @"a";
    RLMArray *array = arObj.array;
    [array addObject:obj];
    [array addObject:[StringObject createInRealm:realm withValue:@[@"b"]]];
    [realm commitWriteTransaction];

    XCTAssertEqual(array.count, 2U, @"Should have two elements in array");
    XCTAssertEqualObjects([array[0] stringCol], @"a", @"First element should have property value 'a'");
    XCTAssertEqualObjects([arObj.array[1] stringCol], @"b", @"Second element should have property value 'b'");

    XCTAssertThrows([array addObject:obj], @"Adding array object outside a transaction should throw");
}

- (void)testDeleteStandaloneObjectWithArrayProperty {
    ArrayPropertyObject *arObj = [[ArrayPropertyObject alloc] initWithValue:@[@"arrayObject", @[@[@"a"]], @[]]];
    RLMArray *stringArray = arObj.array;
    XCTAssertFalse(stringArray.isInvalidated, @"stringArray should be valid after creation.");
    arObj = nil;
    XCTAssertFalse(stringArray.isInvalidated, @"stringArray should still be valid after parent deletion.");
}

- (void)testDeleteObjectWithArrayProperty {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *arObj = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[@[@"a"]], @[]]];
    RLMArray *stringArray = arObj.array;
    XCTAssertFalse(stringArray.isInvalidated, @"stringArray should be valid after creation.");
    [realm deleteObject:arObj];
    XCTAssertTrue(stringArray.isInvalidated, @"stringArray should be invalid after parent deletion.");
    [realm commitWriteTransaction];
}

- (void)testDeleteObjectInArrayProperty {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *arObj = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[@[@"a"]], @[]]];
    RLMArray *stringArray = arObj.array;
    StringObject *firstObject = stringArray.firstObject;
    [realm deleteObjects:[StringObject allObjectsInRealm:realm]];
    XCTAssertFalse(stringArray.isInvalidated, @"stringArray should be valid after member object deletion.");
    XCTAssertTrue(firstObject.isInvalidated, @"firstObject should be invalid after deletion.");
    XCTAssertEqual(stringArray.count, 0U, @"stringArray.count should be zero after deleting its only member.");
    [realm commitWriteTransaction];
}

-(void)testInsertMultiple {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *obj = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[], @[]]];
    StringObject *child1 = [StringObject createInRealm:realm withValue:@[@"a"]];
    StringObject *child2 = [[StringObject alloc] init];
    child2.stringCol = @"b";
    [obj.array addObjects:@[child2, child1]];
    [realm commitWriteTransaction];

    RLMResults *children = [StringObject allObjectsInRealm:realm];
    XCTAssertEqualObjects([children[0] stringCol], @"a", @"First child should be 'a'");
    XCTAssertEqualObjects([children[1] stringCol], @"b", @"Second child should be 'b'");
}

-(void)testInsertAtIndex {
    RLMRealm *realm = [self realmWithTestPath];

    [realm beginWriteTransaction];
    ArrayPropertyObject *obj = [ArrayPropertyObject createInRealm:realm withValue:@[@"arrayObject", @[], @[]]];
    StringObject *child1 = [StringObject createInRealm:realm withValue:@[@"a"]];
    StringObject *child2 = [[StringObject alloc] init];
    child2.stringCol = @"b";
    [obj.array addObject:child2];
    XCTAssertThrows([obj.array insertObject:child1 atIndex:2]);
    [realm commitWriteTransaction];

    RLMArray *children = obj.array;
    XCTAssertEqual(children.count, 1U);
    XCTAssertEqualObjects([children[0] stringCol], @"b", @"Only child should be 'b'");
}

- (void)testMove {
    RLMRealm *realm = [self realmWithTestPath];

    ArrayPropertyObject *obj = [[ArrayPropertyObject alloc] initWithValue:@[@"arrayObject", @[@[@"a"], @[@"b"]], @[]]];
    RLM_GENERIC_ARRAY(StringObject) *children = obj.array;

    [children moveObjectAtIndex:1 toIndex:0];

    XCTAssertEqualObjects([children[0] stringCol], @"b");
    XCTAssertEqualObjects([children[1] stringCol], @"a");

    [children moveObjectAtIndex:0 toIndex:1];

    XCTAssertEqualObjects([children[0] stringCol], @"a");
    XCTAssertEqualObjects([children[1] stringCol], @"b");

    [children moveObjectAtIndex:0 toIndex:0];

    XCTAssertEqualObjects([children[0] stringCol], @"a");
    XCTAssertEqualObjects([children[1] stringCol], @"b");

    XCTAssertThrows([children moveObjectAtIndex:0 toIndex:2]);
    XCTAssertThrows([children moveObjectAtIndex:2 toIndex:0]);

    [realm beginWriteTransaction];

    [realm addObject:obj];
    children = obj.array;

    [children moveObjectAtIndex:1 toIndex:0];

    XCTAssertEqualObjects([children[0] stringCol], @"b");
    XCTAssertEqualObjects([children[1] stringCol], @"a");

    [children moveObjectAtIndex:0 toIndex:1];

    XCTAssertEqualObjects([children[0] stringCol], @"a");
    XCTAssertEqualObjects([children[1] stringCol], @"b");

    [children moveObjectAtIndex:0 toIndex:0];

    XCTAssertEqualObjects([children[0] stringCol], @"a");
    XCTAssertEqualObjects([children[1] stringCol], @"b");

    XCTAssertThrows([children moveObjectAtIndex:0 toIndex:2]);
    XCTAssertThrows([children moveObjectAtIndex:2 toIndex:0]);

    [realm commitWriteTransaction];

    XCTAssertThrows([children moveObjectAtIndex:1 toIndex:0]);
}

- (void)testAddInvalidated {
    RLMRealm *realm = [RLMRealm defaultRealm];

    [realm beginWriteTransaction];
    CompanyObject *company = [CompanyObject createInDefaultRealmWithValue:@[@"company", @[]]];

    EmployeeObject *person = [[EmployeeObject alloc] init];
    person.name = @"Mary";
    [realm addObject:person];
    [realm deleteObjects:[EmployeeObject allObjects]];

    XCTAssertThrowsSpecificNamed([company.employees addObject:person], NSException, @"RLMException");
    XCTAssertThrowsSpecificNamed([company.employees insertObject:person atIndex:0], NSException, @"RLMException");
}

-(void)testStandalone {
    RLMRealm *realm = [self realmWithTestPath];

    ArrayPropertyObject *array = [[ArrayPropertyObject alloc] init];
    array.name = @"name";
    XCTAssertNotNil(array.array, @"RLMArray property should get created on access");

    XCTAssertNil(array.array.firstObject, @"No objects added yet");
    XCTAssertNil(array.array.lastObject, @"No objects added yet");

    StringObject *obj1 = [[StringObject alloc] init];
    obj1.stringCol = @"a";
    StringObject *obj2 = [[StringObject alloc] init];
    obj2.stringCol = @"b";
    StringObject *obj3 = [[StringObject alloc] init];
    obj3.stringCol = @"c";
    [array.array addObject:obj1];
    [array.array addObject:obj2];
    [array.array addObject:obj3];

    XCTAssertEqualObjects(array.array.firstObject, obj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.array.lastObject, obj3, @"Objects should be equal");
    XCTAssertEqualObjects([array.array objectAtIndex:1], obj2, @"Objects should be equal");

    [realm beginWriteTransaction];
    [realm addObject:array];
    [realm commitWriteTransaction];

    XCTAssertEqual(array.array.count, 3U, @"Should have two elements in array");
    XCTAssertEqualObjects([array.array[0] stringCol], @"a", @"First element should have property value 'a'");
    XCTAssertEqualObjects([array.array[1] stringCol], @"b", @"Second element should have property value 'b'");

    [realm beginWriteTransaction];
    [array.array replaceObjectAtIndex:0 withObject:obj3];
    XCTAssertTrue([[array.array objectAtIndex:0] isEqualToObject:obj3], @"Objects should be replaced");
    array.array[0] = obj1;
    XCTAssertTrue([obj1 isEqualToObject:[array.array objectAtIndex:0]], @"Objects should be replaced");
    [array.array removeLastObject];
    XCTAssertEqual(array.array.count, 2U, @"2 objects left");
    [array.array addObject:obj1];
    [array.array removeAllObjects];
    XCTAssertEqual(array.array.count, 0U, @"All objects removed");
    [realm commitWriteTransaction];

    ArrayPropertyObject *intArray = [[ArrayPropertyObject alloc] init];
    IntObject *intObj = [[IntObject alloc] init];
    intObj.intCol = 1;
    XCTAssertThrows([intArray.array addObject:(StringObject *)intObj], @"Addint to string array should throw");
    [intArray.intArray addObject:intObj];

    XCTAssertThrows([intArray.intArray objectsWhere:@"intCol == 1"], @"Should throw on standalone RLMArray");
    XCTAssertThrows(([intArray.intArray objectsWithPredicate:[NSPredicate predicateWithFormat:@"intCol == %i", 1]]), @"Should throw on standalone RLMArray");
    XCTAssertThrows([intArray.intArray sortedResultsUsingProperty:@"intCol" ascending:YES], @"Should throw on standalone RLMArray");

    XCTAssertEqual(0U, [intArray.intArray indexOfObjectWhere:@"intCol == 1"]);
    XCTAssertEqual(0U, ([intArray.intArray indexOfObjectWithPredicate:[NSPredicate predicateWithFormat:@"intCol == %i", 1]]));

    XCTAssertEqual([intArray.intArray indexOfObject:intObj], 0U, @"Should be first element");
    XCTAssertEqual([intArray.intArray indexOfObject:intObj], 0U, @"Should be first element");

    // test standalone with literals
    __unused ArrayPropertyObject *obj = [[ArrayPropertyObject alloc] initWithValue:@[@"n", @[], @[[[IntObject alloc] initWithValue:@[@1]]]]];
}

- (void)testReplaceObjectAtIndexInStandaloneArray {
    ArrayPropertyObject *array = [[ArrayPropertyObject alloc] init];
    array.name = @"name";

    StringObject *stringObj1 = [[StringObject alloc] init];
    stringObj1.stringCol = @"a";
    StringObject *stringObj2 = [[StringObject alloc] init];
    stringObj2.stringCol = @"b";
    StringObject *stringObj3 = [[StringObject alloc] init];
    stringObj3.stringCol = @"c";
    [array.array addObject:stringObj1];
    [array.array addObject:stringObj2];
    [array.array addObject:stringObj3];

    IntObject *intObj1 = [[IntObject alloc] init];
    intObj1.intCol = 0;
    IntObject *intObj2 = [[IntObject alloc] init];
    intObj2.intCol = 1;
    IntObject *intObj3 = [[IntObject alloc] init];
    intObj3.intCol = 2;
    [array.intArray addObject:intObj1];
    [array.intArray addObject:intObj2];
    [array.intArray addObject:intObj3];

    XCTAssertEqualObjects(array.array[0], stringObj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.array[1], stringObj2, @"Objects should be equal");
    XCTAssertEqualObjects(array.array[2], stringObj3, @"Objects should be equal");
    XCTAssertEqual(array.array.count, 3U, @"Should have 3 elements in string array");

    XCTAssertEqualObjects(array.intArray[0], intObj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.intArray[1], intObj2, @"Objects should be equal");
    XCTAssertEqualObjects(array.intArray[2], intObj3, @"Objects should be equal");
    XCTAssertEqual(array.intArray.count, 3U, @"Should have 3 elements in int array");

    StringObject *stringObj4 = [[StringObject alloc] init];
    stringObj4.stringCol = @"d";

    [array.array replaceObjectAtIndex:0 withObject:stringObj4];
    XCTAssertTrue([[array.array objectAtIndex:0] isEqualToObject:stringObj4], @"Objects should be replaced");
    XCTAssertEqual(array.array.count, 3U, @"Should have 3 elements in int array");

    IntObject *intObj4 = [[IntObject alloc] init];
    intObj4.intCol = 3;

    [array.intArray replaceObjectAtIndex:1 withObject:intObj4];
    XCTAssertTrue([[array.intArray objectAtIndex:1] isEqualToObject:intObj4], @"Objects should be replaced");
    XCTAssertEqual(array.intArray.count, 3U, @"Should have 3 elements in int array");

    XCTAssertThrows([array.array replaceObjectAtIndex:0 withObject:(StringObject *)intObj4], @"Throws exception throws when type mismatched");
    XCTAssertThrows([array.intArray replaceObjectAtIndex:1 withObject:(IntObject *)stringObj4], @"Throws exception when type mismatched");
}

- (void)testDeleteObjectInStandaloneArray {
    ArrayPropertyObject *array = [[ArrayPropertyObject alloc] init];
    array.name = @"name";

    StringObject *stringObj1 = [[StringObject alloc] init];
    stringObj1.stringCol = @"a";
    StringObject *stringObj2 = [[StringObject alloc] init];
    stringObj2.stringCol = @"b";
    StringObject *stringObj3 = [[StringObject alloc] init];
    stringObj3.stringCol = @"c";
    [array.array addObject:stringObj1];
    [array.array addObject:stringObj2];
    [array.array addObject:stringObj3];

    IntObject *intObj1 = [[IntObject alloc] init];
    intObj1.intCol = 0;
    IntObject *intObj2 = [[IntObject alloc] init];
    intObj2.intCol = 1;
    IntObject *intObj3 = [[IntObject alloc] init];
    intObj3.intCol = 2;
    [array.intArray addObject:intObj1];
    [array.intArray addObject:intObj2];
    [array.intArray addObject:intObj3];

    XCTAssertEqualObjects(array.array[0], stringObj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.array[1], stringObj2, @"Objects should be equal");
    XCTAssertEqualObjects(array.array[2], stringObj3, @"Objects should be equal");
    XCTAssertEqual(array.array.count, 3U, @"Should have 3 elements in string array");

    XCTAssertEqualObjects(array.intArray[0], intObj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.intArray[1], intObj2, @"Objects should be equal");
    XCTAssertEqualObjects(array.intArray[2], intObj3, @"Objects should be equal");
    XCTAssertEqual(array.intArray.count, 3U, @"Should have 3 elements in int array");

    [array.array removeLastObject];

    XCTAssertEqualObjects(array.array[0], stringObj1, @"Objects should be equal");
    XCTAssertEqualObjects(array.array[1], stringObj2, @"Objects should be equal");
    XCTAssertEqual(array.array.count, 2U, @"Should have 2 elements in string array");

    [array.array removeLastObject];

    XCTAssertEqualObjects(array.array[0], stringObj1, @"Objects should be equal");
    XCTAssertEqual(array.array.count, 1U, @"Should have 1 elements in string array");

    [array.array removeLastObject];

    XCTAssertEqual(array.array.count, 0U, @"Should have 0 elements in string array");

    [array.intArray removeAllObjects];
    XCTAssertEqual(array.intArray.count, 0U, @"Should have 0 elements in int array");
}

- (void)testExchangeObjectAtIndexWithObjectAtIndex {

    void (^test)(RLMArray *) = ^(RLMArray *array) {
        [array exchangeObjectAtIndex:0 withObjectAtIndex:1];
        XCTAssertEqual(2U, array.count);
        XCTAssertEqualObjects(@"b", [array[0] stringCol]);
        XCTAssertEqualObjects(@"a", [array[1] stringCol]);

        [array exchangeObjectAtIndex:1 withObjectAtIndex:1];
        XCTAssertEqual(2U, array.count);
        XCTAssertEqualObjects(@"b", [array[0] stringCol]);
        XCTAssertEqualObjects(@"a", [array[1] stringCol]);

        [array exchangeObjectAtIndex:1 withObjectAtIndex:0];
        XCTAssertEqual(2U, array.count);
        XCTAssertEqualObjects(@"a", [array[0] stringCol]);
        XCTAssertEqualObjects(@"b", [array[1] stringCol]);

        XCTAssertThrows([array exchangeObjectAtIndex:1 withObjectAtIndex:20]);
    };

    ArrayPropertyObject *array = [[ArrayPropertyObject alloc] initWithValue:@[@"foo", @[@[@"a"], @[@"b"]], @[]]];
    test(array.array);

    RLMRealm *realm = [RLMRealm defaultRealm];
    [realm beginWriteTransaction];
    [realm addObject:array];
    test(array.array);
    [realm commitWriteTransaction];
}

- (void)testIndexOfObject
{
    RLMRealm *realm = [RLMRealm defaultRealm];

    [realm beginWriteTransaction];
    EmployeeObject *po1 = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @40, @"hired": @YES}];
    EmployeeObject *po2 = [EmployeeObject createInRealm:realm withValue:@{@"name": @"John", @"age": @30, @"hired": @NO}];
    EmployeeObject *po3 = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Jill", @"age": @25, @"hired": @YES}];

    // create company
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";
    [company.employees addObjects:[EmployeeObject allObjects]];
    [company.employees removeObjectAtIndex:1];

    // test standalone
    XCTAssertEqual(0U, [company.employees indexOfObject:po1]);
    XCTAssertEqual(1U, [company.employees indexOfObject:po3]);
    XCTAssertEqual((NSUInteger)NSNotFound, [company.employees indexOfObject:po2]);

    // add to realm
    [realm addObject:company];
    [realm commitWriteTransaction];

    // test LinkView RLMArray
    XCTAssertEqual(0U, [company.employees indexOfObject:po1]);
    XCTAssertEqual(1U, [company.employees indexOfObject:po3]);
    XCTAssertEqual((NSUInteger)NSNotFound, [company.employees indexOfObject:po2]);

    // non realm employee
    EmployeeObject *notInRealm = [[EmployeeObject alloc] initWithValue:@[@"NoName", @1, @NO]];
    XCTAssertEqual((NSUInteger)NSNotFound, [company.employees indexOfObject:notInRealm]);

    // invalid object
    XCTAssertThrows([company.employees indexOfObject:(EmployeeObject *)company]);
}

- (void)testIndexOfObjectWhere
{
    RLMRealm *realm = [RLMRealm defaultRealm];

    [realm beginWriteTransaction];
    EmployeeObject *po1 = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @40, @"hired": @YES}];
    [EmployeeObject createInRealm:realm withValue:@{@"name": @"John", @"age": @30, @"hired": @NO}];
    EmployeeObject *po3 = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Jill", @"age": @25, @"hired": @YES}];

    // create company
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";
    [company.employees addObjects:@[po3, po1]];

    // test standalone
    XCTAssertEqual(0U, [company.employees indexOfObjectWhere:@"name = 'Jill'"]);
    XCTAssertEqual(1U, [company.employees indexOfObjectWhere:@"name = 'Joe'"]);
    XCTAssertEqual((NSUInteger)NSNotFound, [company.employees indexOfObjectWhere:@"name = 'John'"]);

    // add to realm
    [realm addObject:company];
    [realm commitWriteTransaction];

    // test LinkView RLMArray
    XCTAssertEqual(0U, [company.employees indexOfObjectWhere:@"name = 'Jill'"]);
    XCTAssertEqual(1U, [company.employees indexOfObjectWhere:@"name = 'Joe'"]);
    XCTAssertEqual((NSUInteger)NSNotFound, [company.employees indexOfObjectWhere:@"name = 'John'"]);
}

- (void)testFastEnumeration
{
    RLMRealm *realm = self.realmWithTestPath;

    [realm beginWriteTransaction];
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";
    [realm addObject:company];
    [realm commitWriteTransaction];

    // enumerate empty array
    for (__unused id obj in company.employees) {
        XCTFail(@"Should be empty");
    }

    [realm beginWriteTransaction];
    for (int i = 0; i < 30; ++i) {
        EmployeeObject *eo = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @40, @"hired": @YES}];
        [company.employees addObject:eo];
    }
    [realm commitWriteTransaction];

    XCTAssertEqual(company.employees.count, 30U);

    __weak id objects[30];
    NSInteger count = 0;
    for (EmployeeObject *e in company.employees) {
        XCTAssertNotNil(e, @"Object is not nil and accessible");
        if (count > 16) {
            // 16 is the size of blocks fast enumeration happens to ask for at
            // the moment, but of course that's just an implementation detail
            // that may change
            XCTAssertNil(objects[count - 16]);
        }
        objects[count++] = e;
    }

    XCTAssertEqual(count, 30, @"should have enumerated 30 objects");

    for (int i = 0; i < count; i++) {
        XCTAssertNil(objects[i], @"Object should have been released");
    }

    @autoreleasepool {
        for (EmployeeObject *e in company.employees) {
            objects[0] = e;
            break;
        }
    }
    XCTAssertNil(objects[0], @"Object should have been released");

    void (^mutateDuringEnumeration)() = ^{
        bool first = true;
        for (__unused EmployeeObject *e in company.employees) {
            // Only insert the first time so we don't infinite loop if the check
            // doesn't work
            if (first) {
                [realm beginWriteTransaction];
                EmployeeObject *eo = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @40, @"hired": @YES}];
                [company.employees addObject:eo];
                [realm commitWriteTransaction];
                first = false;
            }
        }
    };

    XCTAssertThrows(mutateDuringEnumeration(),
                    @"Adding an object during fast enumeration did not throw");
}

- (void)testValueForKey {
    RLMRealm *realm = self.realmWithTestPath;

    [realm beginWriteTransaction];
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";
    XCTAssertEqualObjects([company.employees valueForKey:@"name"], @[]);
    [realm addObject:company];
    [realm commitWriteTransaction];

    XCTAssertEqualObjects([company.employees valueForKey:@"age"], @[]);

    // persisted
    NSMutableArray *ages = [NSMutableArray array];
    [realm beginWriteTransaction];
    for (int i = 0; i < 30; ++i) {
        [ages addObject:@(i)];
        EmployeeObject *eo = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @(i), @"hired": @YES}];
        [company.employees addObject:eo];
    }
    [realm commitWriteTransaction];

    XCTAssertEqualObjects([company.employees valueForKey:@"age"], ages);
    XCTAssertTrue([[[company.employees valueForKey:@"self"] firstObject] isEqualToObject:company.employees.firstObject]);
    XCTAssertTrue([[[company.employees valueForKey:@"self"] lastObject] isEqualToObject:company.employees.lastObject]);

    // standalone
    company = [[CompanyObject alloc] init];
    ages = [NSMutableArray array];
    for (int i = 0; i < 30; ++i) {
        [ages addObject:@(i)];
        EmployeeObject *eo = [[EmployeeObject alloc] initWithValue:@{@"name": @"Joe",  @"age": @(i), @"hired": @YES}];
        [company.employees addObject:eo];
    }

    XCTAssertEqualObjects([company.employees valueForKey:@"age"], ages);
    XCTAssertTrue([[[company.employees valueForKey:@"self"] firstObject] isEqualToObject:company.employees.firstObject]);
    XCTAssertTrue([[[company.employees valueForKey:@"self"] lastObject] isEqualToObject:company.employees.lastObject]);
}

- (void)testSetValueForKey {
    RLMRealm *realm = self.realmWithTestPath;

    [realm beginWriteTransaction];
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";

    [company.employees setValue:@"name" forKey:@"name"];
    XCTAssertEqualObjects([company.employees valueForKey:@"name"], @[]);

    [realm addObject:company];
    [realm commitWriteTransaction];

    XCTAssertThrows([company.employees setValue:@10 forKey:@"age"]);
    XCTAssertEqualObjects([company.employees valueForKey:@"age"], @[]);

    // persisted
    NSMutableArray *ages = [NSMutableArray array];
    [realm beginWriteTransaction];
    for (int i = 0; i < 30; ++i) {
        [ages addObject:@(20)];
        EmployeeObject *eo = [EmployeeObject createInRealm:realm withValue:@{@"name": @"Joe",  @"age": @(i), @"hired": @YES}];
        [company.employees addObject:eo];
    }

    [company.employees setValue:@20 forKey:@"age"];
    [realm commitWriteTransaction];

    XCTAssertEqualObjects([company.employees valueForKey:@"age"], ages);

    // standalone
    company = [[CompanyObject alloc] init];
    ages = [NSMutableArray array];
    for (int i = 0; i < 30; ++i) {
        [ages addObject:@(20)];
        EmployeeObject *eo = [[EmployeeObject alloc] initWithValue:@{@"name": @"Joe",  @"age": @(i), @"hired": @YES}];
        [company.employees addObject:eo];
    }

    [company.employees setValue:@20 forKey:@"age"];

    XCTAssertEqualObjects([company.employees valueForKey:@"age"], ages);
}

- (void)testCrossThreadAccess
{
    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";

    EmployeeObject *eo = [[EmployeeObject alloc] init];
    eo.name = @"Joe";
    eo.age = 40;
    eo.hired = YES;
    [company.employees addObject:eo];
    RLMArray *employees = company.employees;

    // Standalone can be accessed from other threads
    // Using dispatch_async to ensure it actually lands on another thread
    dispatch_queue_t queue = dispatch_queue_create("background", 0);
    dispatch_async(queue, ^{
        XCTAssertNoThrow(company.employees);
        XCTAssertNoThrow([employees lastObject]);
    });
    dispatch_sync(queue, ^{});

    [RLMRealm.defaultRealm beginWriteTransaction];
    [RLMRealm.defaultRealm addObject:company];
    [RLMRealm.defaultRealm commitWriteTransaction];

    employees = company.employees;
    XCTAssertNoThrow(company.employees);
    XCTAssertNoThrow([employees lastObject]);
    dispatch_async(queue, ^{
        XCTAssertThrows(company.employees);
        XCTAssertThrows([employees lastObject]);
    });
    dispatch_sync(queue, ^{});
}

- (void)testSortByMultipleColumns {
    RLMRealm *realm = [RLMRealm defaultRealm];
    [realm beginWriteTransaction];
    DogObject *a1 = [DogObject createInDefaultRealmWithValue:@[@"a", @1]];
    DogObject *a2 = [DogObject createInDefaultRealmWithValue:@[@"a", @2]];
    DogObject *b1 = [DogObject createInDefaultRealmWithValue:@[@"b", @1]];
    DogObject *b2 = [DogObject createInDefaultRealmWithValue:@[@"b", @2]];

    DogArrayObject *array = [DogArrayObject createInDefaultRealmWithValue:@[@[a1, a2, b1, b2]]];
    [realm commitWriteTransaction];

    bool (^checkOrder)(NSArray *, NSArray *, NSArray *) = ^bool(NSArray *properties, NSArray *ascending, NSArray *dogs) {
        NSArray *sort = @[[RLMSortDescriptor sortDescriptorWithProperty:properties[0] ascending:[ascending[0] boolValue]],
                          [RLMSortDescriptor sortDescriptorWithProperty:properties[1] ascending:[ascending[1] boolValue]]];
        RLMResults *actual = [array.dogs sortedResultsUsingDescriptors:sort];

        return [actual[0] isEqualToObject:dogs[0]]
            && [actual[1] isEqualToObject:dogs[1]]
            && [actual[2] isEqualToObject:dogs[2]]
            && [actual[3] isEqualToObject:dogs[3]];
    };

    // Check each valid sort
    XCTAssertTrue(checkOrder(@[@"dogName", @"age"], @[@YES, @YES], @[a1, a2, b1, b2]));
    XCTAssertTrue(checkOrder(@[@"dogName", @"age"], @[@YES, @NO], @[a2, a1, b2, b1]));
    XCTAssertTrue(checkOrder(@[@"dogName", @"age"], @[@NO, @YES], @[b1, b2, a1, a2]));
    XCTAssertTrue(checkOrder(@[@"dogName", @"age"], @[@NO, @NO], @[b2, b1, a2, a1]));
    XCTAssertTrue(checkOrder(@[@"age", @"dogName"], @[@YES, @YES], @[a1, b1, a2, b2]));
    XCTAssertTrue(checkOrder(@[@"age", @"dogName"], @[@YES, @NO], @[b1, a1, b2, a2]));
    XCTAssertTrue(checkOrder(@[@"age", @"dogName"], @[@NO, @YES], @[a2, b2, a1, b1]));
    XCTAssertTrue(checkOrder(@[@"age", @"dogName"], @[@NO, @NO], @[b2, a2, b1, a1]));
}

- (void)testDeleteLinksAndObjectsInArray
{
    RLMRealm *realm = [RLMRealm defaultRealm];
    [realm beginWriteTransaction];
    EmployeeObject *po1 = [EmployeeObject createInRealm:realm withValue:@[@"Joe", @40, @YES]];
    EmployeeObject *po2 = [EmployeeObject createInRealm:realm withValue:@[@"John", @30, @NO]];
    EmployeeObject *po3 = [EmployeeObject createInRealm:realm withValue:@[@"Jill", @25, @YES]];

    CompanyObject *company = [[CompanyObject alloc] init];
    company.name = @"name";
    [company.employees addObjects:[EmployeeObject allObjects]];
    [realm addObject:company];

    [realm commitWriteTransaction];

    RLMArray *peopleInCompany = company.employees;

    // Delete link to employee
    XCTAssertThrowsSpecificNamed([peopleInCompany removeObjectAtIndex:1], NSException, @"RLMException", @"Not allowed in read transaction");
    XCTAssertEqual(peopleInCompany.count, 3U, @"No links should have been deleted");

    [realm beginWriteTransaction];
    XCTAssertThrowsSpecificNamed([peopleInCompany removeObjectAtIndex:3], NSException, @"RLMException", @"Out of bounds");
    XCTAssertNoThrow([peopleInCompany removeObjectAtIndex:1], @"Should delete link to employee");
    [realm commitWriteTransaction];

    XCTAssertEqual(peopleInCompany.count, 2U, @"link deleted when accessing via links");
    EmployeeObject *test = peopleInCompany[0];
    XCTAssertEqual(test.age, po1.age, @"Should be equal");
    XCTAssertEqualObjects(test.name, po1.name, @"Should be equal");
    XCTAssertEqual(test.hired, po1.hired, @"Should be equal");
    XCTAssertTrue([test isEqualToObject:po1], @"Should be equal");

    test = peopleInCompany[1];
    XCTAssertEqual(test.age, po3.age, @"Should be equal");
    XCTAssertEqualObjects(test.name, po3.name, @"Should be equal");
    XCTAssertEqual(test.hired, po3.hired, @"Should be equal");
    XCTAssertTrue([test isEqualToObject:po3], @"Should be equal");

    XCTAssertThrowsSpecificNamed([peopleInCompany removeLastObject], NSException, @"RLMException", @"Not allowed in read transaction");
    XCTAssertThrowsSpecificNamed([peopleInCompany removeAllObjects], NSException, @"RLMException", @"Not allowed in read transaction");
    XCTAssertThrowsSpecificNamed([peopleInCompany replaceObjectAtIndex:0 withObject:po2], NSException, @"RLMException", @"Not allowed in read transaction");
    XCTAssertThrowsSpecificNamed([peopleInCompany insertObject:po2 atIndex:0], NSException, @"RLMException", @"Not allowed in read transaction");

    [realm beginWriteTransaction];
    XCTAssertNoThrow([peopleInCompany removeLastObject], @"Should delete last link");
    XCTAssertEqual(peopleInCompany.count, 1U, @"1 remaining link");
    [peopleInCompany replaceObjectAtIndex:0 withObject:po2];
    XCTAssertEqual(peopleInCompany.count, 1U, @"1 link replaced");
    [peopleInCompany insertObject:po1 atIndex:0];
    XCTAssertEqual(peopleInCompany.count, 2U, @"2 links");
    XCTAssertNoThrow([peopleInCompany removeAllObjects], @"Should delete all links");
    XCTAssertEqual(peopleInCompany.count, 0U, @"0 remaining links");
    [realm commitWriteTransaction];

    RLMResults *allPeople = [EmployeeObject allObjects];
    XCTAssertEqual(allPeople.count, 3U, @"Only links should have been deleted, not the employees");
}

- (void)testArrayDescription {
    RLMRealm *realm = [RLMRealm defaultRealm];

    [realm beginWriteTransaction];
    CompanyObject *company = [CompanyObject createInDefaultRealmWithValue:@[@"company", @[]]];
    for (NSInteger i = 0; i < 1012; ++i) {
        EmployeeObject *person = [[EmployeeObject alloc] init];
        person.name = @"Mary";
        person.age = 24;
        person.hired = YES;
        [company.employees addObject:person];
        [realm addObject:person];
    }
    [realm commitWriteTransaction];

    NSString *description = [company.employees description];

    XCTAssertTrue([description rangeOfString:@"name"].location != NSNotFound);
    XCTAssertTrue([description rangeOfString:@"Mary"].location != NSNotFound);

    XCTAssertTrue([description rangeOfString:@"age"].location != NSNotFound);
    XCTAssertTrue([description rangeOfString:@"24"].location != NSNotFound);

    XCTAssertTrue([description rangeOfString:@"912 objects skipped"].location != NSNotFound);
}

@end
