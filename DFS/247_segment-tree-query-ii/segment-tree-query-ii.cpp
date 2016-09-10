/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/segment-tree-query-ii
@Language: C++
@Datetime: 16-06-25 04:16
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    // int query(SegmentTreeNode *root, int start, int end) {
    //     // write your code here
    // if(root->start>end || root->end<start ||root==nullptr) return 0;
    
    // if(root->start>=start && root->end<=end) 
    // {
    // return root->count;
    // }
    // //[start,root->start,root->right,right];

    // int left=query(root->left,start,end);
    // int right=query(root->right,start,end);
    
    // return left+right;
    
    // }
    
     int query(SegmentTreeNode *root, int start, int end) {
        // Out of range.
        if (root == nullptr || root->start > end || root->end <  start) {
            return 0;
        }

        // Current segment is totally within range [start, end]
        if (root->start >= start && root->end <= end) {
            return root->count;
        }

        int left = query(root->left, start, end);
        int right = query(root->right, start, end);

        // Find max in the children.
        return left + right;
    }
};