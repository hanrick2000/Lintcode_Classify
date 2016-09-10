/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 16-08-23 03:31
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */

    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(A.empty()) return NULL;
        
        return sortedArrayToBST(A,0,A.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &A ,int start,int end) {
        // write your code here
        
        if(start>end) return NULL;
        
        int mid = start +(end-start)/2;
        TreeNode * node = new TreeNode(A[mid]);
        node->left = sortedArrayToBST(A,start,mid-1);
        node->right = sortedArrayToBST(A,mid+1,end);
        
        return node;
    }
};


