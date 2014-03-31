/*
 * Copyright 2010-2013 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#import "DynamoDBCondition.h"
#import "DynamoDBAttributeValue.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Scan Request
 */

@interface DynamoDBScanRequest:AmazonServiceRequestConfig

{
    NSString            *tableName;
    NSMutableArray      *attributesToGet;
    NSNumber            *limit;
    NSString            *select;
    NSMutableDictionary *scanFilter;
    NSMutableDictionary *exclusiveStartKey;
    NSString            *returnConsumedCapacity;
    NSNumber            *totalSegments;
    NSNumber            *segment;
}



/**
 * The name of the table containing the requested items.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>3 - 255<br/>
 * <b>Pattern: </b>[a-zA-Z0-9_.-]+<br/>
 */
@property (nonatomic, retain) NSString *tableName;

/**
 * The names of one or more attributes to retrieve. If no attribute names
 * are specified, then all attributes will be returned. If any of the
 * requested attributes are not found, they will not appear in the
 * result.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - <br/>
 */
@property (nonatomic, retain) NSMutableArray *attributesToGet;

/**
 * The maximum number of items to evaluate (not necessarily the number of
 * matching items). If Amazon DynamoDB processes the number of items up
 * to the limit while processing the results, it stops the operation and
 * returns the matching values up to that point, and a
 * <i>LastEvaluatedKey</i> to apply in a subsequent operation, so that
 * you can pick up where you left off. Also, if the processed data set
 * size exceeds 1 MB before Amazon DynamoDB reaches this limit, it stops
 * the operation and returns the matching values up to the limit, and a
 * <i>LastEvaluatedKey</i> to apply in a subsequent operation to continue
 * the operation. For more information see <a
 * azon.com/amazondynamodb/latest/developerguide/QueryAndScan.html">Query
 * and Scan</a> in the Amazon DynamoDB Developer Guide.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Range: </b>1 - <br/>
 */
@property (nonatomic, retain) NSNumber *limit;

/**
 * The attributes to be returned in the result. You can retrieve all item
 * attributes, specific item attributes, or the count of matching items.
 * <ul> <li> <p><code>ALL_ATTRIBUTES</code>: Returns all of the item
 * attributes. </li> <li> <p><code>COUNT</code>: Returns the number of
 * matching items, rather than the matching items themselves. </li> <li>
 * <p> <code>SPECIFIC_ATTRIBUTES</code> : Returns only the attributes
 * listed in <i>AttributesToGet</i>. This is equivalent to specifying
 * <i>AttributesToGet</i> without specifying any value for <i>Select</i>.
 * </li> </ul> <p>If neither <i>Select</i> nor <i>AttributesToGet</i> are
 * specified, Amazon DynamoDB defaults to <code>ALL_ATTRIBUTES</code>.
 * You cannot use both <i>Select</i> and <i>AttributesToGet</i> together
 * in a single request, <i>unless</i> the value for <i>Select</i> is
 * <code>SPECIFIC_ATTRIBUTES</code>. (This usage is equivalent to
 * specifying <i>AttributesToGet</i> without any value for
 * <i>Select</i>.)
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>ALL_ATTRIBUTES, ALL_PROJECTED_ATTRIBUTES, SPECIFIC_ATTRIBUTES, COUNT
 */
@property (nonatomic, retain) NSString *select;

/**
 * Evaluates the scan results and returns only the desired values.
 * Multiple conditions are treated as "AND" operations: all conditions
 * must be met to be included in the results. <p>Each
 * <i>ScanConditions</i> element consists of an attribute name to
 * compare, along with the following: <ul>
 * <li><p><i>AttributeValueList</i> - One or more values to evaluate
 * against the supplied attribute. This list contains exactly one value,
 * except for a <code>BETWEEN</code> or <code>IN</code> comparison, in
 * which case the list contains two values. <note> <p>For type Number,
 * value comparisons are numeric. <p>String value comparisons for greater
 * than, equals, or less than are based on ASCII character code values.
 * For example, <code>a</code> is greater than <code>A</code>, and
 * <code>aa</code> is greater than <code>B</code>. For a list of code
 * values, see <a
 * rs">http://en.wikipedia.org/wiki/ASCII#ASCII_printable_characters</a>.
 * <p>For Binary, Amazon DynamoDB treats each byte of the binary data as
 * unsigned when it compares binary values, for example when evaluating
 * query expressions. </note> </li> <li><p><i>ComparisonOperator</i> - A
 * comparator for evaluating attributes. For example, equals, greater
 * than, less than, etc. <p>Valid comparison operators for Scan:
 * <p><code>EQ | NE | LE | LT | GE | GT | NOT_NULL | NULL | CONTAINS |
 * NOT_CONTAINS | BEGINS_WITH | IN | BETWEEN</code> <p>For information on
 * specifying data types in JSON, see <a
 * .amazon.com/amazondynamodb/latest/developerguide/DataFormat.html">JSON
 * Data Format</a> in the Amazon DynamoDB Developer Guide. <p>The
 * following are descriptions of each comparison operator. <ul> <li>
 * <p><code>EQ</code> : Equal. <p><i>AttributeValueList</i> can contain
 * only one <i>AttributeValue</i> of type String, Number, or Binary (not
 * a set). If an item contains an <i>AttributeValue</i> of a different
 * type than the one specified in the request, the value does not match.
 * For example, <code>{"S":"6"}</code> does not equal
 * <code>{"N":"6"}</code>. Also, <code>{"N":"6"}</code> does not equal
 * <code>{"NS":["6", "2", "1"]}</code>. <p> </li> <li> <p><code>NE</code>
 * : Not equal. <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If an item contains an <i>AttributeValue</i> of a different type than
 * the one specified in the request, the value does not match. For
 * example, <code>{"S":"6"}</code> does not equal <code>{"N":"6"}</code>.
 * Also, <code>{"N":"6"}</code> does not equal <code>{"NS":["6", "2",
 * "1"]}</code>. <p> </li> <li> <p><code>LE</code> : Less than or equal.
 * <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If an item contains an <i>AttributeValue</i> of a different type than
 * the one specified in the request, the value does not match. For
 * example, <code>{"S":"6"}</code> does not equal <code>{"N":"6"}</code>.
 * Also, <code>{"N":"6"}</code> does not compare to <code>{"NS":["6",
 * "2", "1"]}</code>. <p> </li> <li> <p><code>LT</code> : Less than.
 * <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If an item contains an <i>AttributeValue</i> of a different type than
 * the one specified in the request, the value does not match. For
 * example, <code>{"S":"6"}</code> does not equal <code>{"N":"6"}</code>.
 * Also, <code>{"N":"6"}</code> does not compare to <code>{"NS":["6",
 * "2", "1"]}</code>. <p> </li> <li> <p><code>GE</code> : Greater than or
 * equal. <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If an item contains an <i>AttributeValue</i> of a different type than
 * the one specified in the request, the value does not match. For
 * example, <code>{"S":"6"}</code> does not equal <code>{"N":"6"}</code>.
 * Also, <code>{"N":"6"}</code> does not compare to <code>{"NS":["6",
 * "2", "1"]}</code>. <p> </li> <li> <p><code>GT</code> : Greater than.
 * <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If an item contains an <i>AttributeValue</i> of a different type than
 * the one specified in the request, the value does not match. For
 * example, <code>{"S":"6"}</code> does not equal <code>{"N":"6"}</code>.
 * Also, <code>{"N":"6"}</code> does not compare to <code>{"NS":["6",
 * "2", "1"]}</code>. <p> </li> <li> <p><code>NOT_NULL</code> : The
 * attribute exists. </li> <li> <p><code>NULL</code> : The attribute does
 * not exist. </li> <li> <p><code>CONTAINS</code> : checks for a
 * subsequence, or value in a set. <p><i>AttributeValueList</i> can
 * contain only one <i>AttributeValue</i> of type String, Number, or
 * Binary (not a set). If the target attribute of the comparison is a
 * String, then the operation checks for a substring match. If the target
 * attribute of the comparison is Binary, then the operation looks for a
 * subsequence of the target that matches the input. If the target
 * attribute of the comparison is a set ("SS", "NS", or "BS"), then the
 * operation checks for a member of the set (not as a substring). </li>
 * <li> <p><code>NOT_CONTAINS</code> : checks for absence of a
 * subsequence, or absence of a value in a set.
 * <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String, Number, or Binary (not a set).
 * If the target attribute of the comparison is a String, then the
 * operation checks for the absence of a substring match. If the target
 * attribute of the comparison is Binary, then the operation checks for
 * the absence of a subsequence of the target that matches the input. If
 * the target attribute of the comparison is a set ("SS", "NS", or "BS"),
 * then the operation checks for the absence of a member of the set (not
 * as a substring). </li> <li> <p><code>BEGINS_WITH</code> : checks for a
 * prefix. <p><i>AttributeValueList</i> can contain only one
 * <i>AttributeValue</i> of type String or Binary (not a Number or a
 * set). The target attribute of the comparison must be a String or
 * Binary (not a Number or a set). <p> </li> <li> <p><code>IN</code> :
 * checks for exact matches. <p><i>AttributeValueList</i> can contain
 * more than one <i>AttributeValue</i> of type String, Number, or Binary
 * (not a set). The target attribute of the comparison must be of the
 * same type and exact value to match. A String never matches a String
 * set. </li> <li> <p><code>BETWEEN</code> : Greater than or equal to the
 * first value, and less than or equal to the second value.
 * <p><i>AttributeValueList</i> must contain two <i>AttributeValue</i>
 * elements of the same type, either String, Number, or Binary (not a
 * set). A target attribute matches if the target value is greater than,
 * or equal to, the first element and less than, or equal to, the second
 * element. If an item contains an <i>AttributeValue</i> of a different
 * type than the one specified in the request, the value does not match.
 * For example, <code>{"S":"6"}</code> does not compare to
 * <code>{"N":"6"}</code>. Also, <code>{"N":"6"}</code> does not compare
 * to <code>{"NS":["6", "2", "1"]}</code> </li> </ul> </li> </ul>
 */
@property (nonatomic, retain) NSMutableDictionary *scanFilter;

/**
 * The primary key of the first item that this operation will evalute.
 * Use the value that was returned for <i>LastEvaluatedKey</i> in the
 * previous operation. <p>The data type for <i>ExclusiveStartKey</i> must
 * be String, Number or Binary. No set data types are allowed. <p>In a
 * parallel scan, a <i>Scan</i> request that includes
 * <i>ExclusiveStartKey</i> must specify the same segment whose previous
 * <i>Scan</i> returned the corresponding value of
 * <i>LastEvaluatedKey</i>.
 */
@property (nonatomic, retain) NSMutableDictionary *exclusiveStartKey;

/**
 * If set to <code>TOTAL</code>, the response includes
 * <i>ConsumedCapacity</i> data for tables and indexes. If set to
 * <code>INDEXES</code>, the repsonse includes <i>ConsumedCapacity</i>
 * for indexes. If set to <code>NONE</code> (the default),
 * <i>ConsumedCapacity</i> is not included in the response.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>INDEXES, TOTAL, NONE
 */
@property (nonatomic, retain) NSString *returnConsumedCapacity;

/**
 * For a parallel <i>Scan</i> request, <i>TotalSegments</i> represents
 * the total number of segments into which the <i>Scan</i> operation will
 * be divided. The value of <i>TotalSegments</i> corresponds to the
 * number of application workers that will perform the parallel scan. For
 * example, if you want to scan a table using four application threads,
 * you would specify a <i>TotalSegments</i> value of 4. <p>The value for
 * <i>TotalSegments</i> must be greater than or equal to 1, and less than
 * or equal to 4096. If you specify a <i>TotalSegments</i> value of 1,
 * the <i>Scan</i> will be sequential rather than parallel. <p>If you
 * specify <i>TotalSegments</i>, you must also specify <i>Segment</i>.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Range: </b>1 - 4096<br/>
 */
@property (nonatomic, retain) NSNumber *totalSegments;

/**
 * For a parallel <i>Scan</i> request, <i>Segment</i> identifies an
 * individual segment to be scanned by an application worker. <p>Segment
 * IDs are zero-based, so the first segment is always 0. For example, if
 * you want to scan a table using four application threads, the first
 * thread would specify a <i>Segment</i> value of 0, the second thread
 * would specify 1, and so on. <p>The value of <i>LastEvaluatedKey</i>
 * returned from a parallel <i>Scan</i> request must be used as
 * <i>ExclusiveStartKey</i> with the same Segment ID in a subsequent
 * <i>Scan</i> operation. <p>The value for <i>Segment</i> must be greater
 * than or equal to 0, and less than the value provided for
 * <i>TotalSegments</i>. <p>If you specify <i>Segment</i>, you must also
 * specify <i>TotalSegments</i>.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Range: </b>0 - 4095<br/>
 */
@property (nonatomic, retain) NSNumber *segment;


/**
 * Default constructor for a new ScanRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new ScanRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theTableName The name of the table containing the requested
 * items.
 */
-(id)initWithTableName:(NSString *)theTableName;

/**
 * Adds a single object to attributesToGet.
 * This function will alloc and init attributesToGet if not already done.
 */
-(void)addAttributesToGet:(NSString *)attributesToGetObject;


/**
 * Set a value in the dictionary scanFilter for the specified key.
 * This function will alloc and init scanFilter if not already done.
 */
-(void)setScanFilterValue:(DynamoDBCondition *)theValue forKey:(NSString *)theKey;


/**
 * Set a value in the dictionary exclusiveStartKey for the specified key.
 * This function will alloc and init exclusiveStartKey if not already done.
 */
-(void)setExclusiveStartKeyValue:(DynamoDBAttributeValue *)theValue forKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
