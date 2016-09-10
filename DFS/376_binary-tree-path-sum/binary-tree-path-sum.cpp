/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-path-sum
@Language: C++
@Datetime: 16-09-06 06:49
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        // Write your code here
        vector<vector<int>>res;
        vector<int>ret;

        binaryTreePathSum(root,target,ret,res);
        
        return res;
    }
    
    void binaryTreePathSum(TreeNode *root, int target,vector<int>&ret,vector<vector<int>> &res)
    {
      if(root == NULL) return;    
      ret.push_back(root->val);    
      if(root->val == target && (root->left == NULL) && (root->right == NULL) ) 
      res.push_back(ret);     
      else
      {
      binaryTreePathSum(root->left,target-root->val,ret,res); 
      binaryTreePathSum(root->right,target-root->val,ret,res); 
      }
      ret.pop_back();
    }
};




