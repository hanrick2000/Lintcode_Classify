/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: C++
@Datetime: 16-07-12 01:50
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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
    
     vector<int>res;
     
     
      helper(root,res,k1,k2);
      
      //sort(res.begin(),res.end());
      
      return res;
}


   void helper(TreeNode*root, vector<int>&res,int k1,int k2)
   {
       if(!root) return;
       
       helper(root->left,res,k1,k2);
       
       if(root->val>=k1 && root->val<=k2)
       res.push_back(root->val);
       
       helper(root->right,res,k1,k2);
       
   }
};