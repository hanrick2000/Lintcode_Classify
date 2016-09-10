/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/flatten-list
@Language: C++
@Datetime: 16-08-31 20:39
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;
        for (const auto& node : nestedList)
            if (node.isInteger()) {
                result.emplace_back(node.getInteger());
            } else {
                vector<NestedInteger> sub_list = node.getList();
                auto temp = flatten(sub_list);
                result.insert(result.end(), temp.begin(), temp.end());
            }

        return result;
    }
};