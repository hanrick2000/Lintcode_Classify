/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/segment-tree-query
@Language: C++
@Datetime: 16-06-25 04:08
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        
    if(root->start>end || root->end<start|| root==NULL) return INT_MIN;
    
    if(root->start>=start && root->end<=end) return root->max;
    
    //[start,root->start,root->right,right];

    int left=query(root->left,start,end);
    int right=query(root->right,start,end);
    
    return max(left,right);
    }
};