/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-08-14 19:23
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        Traversal(root,res);
        
        return res;
    }
    
private:
       
    void Traversal(TreeNode *root,vector<int>& res) {
        // write your code here
        if(root==NULL) return;
            
        Traversal(root->left,res); 
        res.push_back(root->val);
        Traversal(root->right,res); 
        return;
    }
};