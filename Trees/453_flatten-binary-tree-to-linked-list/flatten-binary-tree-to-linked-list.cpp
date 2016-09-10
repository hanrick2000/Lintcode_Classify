/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-08-27 05:34
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        
        if(!root) return;
        vector<TreeNode*> allNodes;
        preorder(root,allNodes);
        int n=allNodes.size();
        
        for(int i=0;i<n-1;i++)
        {
          allNodes[i]->left = NULL;    
          allNodes[i]->right = allNodes[i+1];    
        }
        allNodes[n-1]->left = allNodes[n-1]->right = NULL;
    }
    
    void preorder(TreeNode*root, vector<TreeNode*> &allNodes)
    {
        if(!root) return;
        allNodes.push_back(root);
        preorder(root->left,allNodes);
        preorder(root->right,allNodes);
    }
    
};