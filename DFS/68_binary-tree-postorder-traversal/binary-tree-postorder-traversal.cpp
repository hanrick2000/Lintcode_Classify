/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-08-14 19:46
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
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
        Traversal(root->right,res); 
        res.push_back(root->val);
        
        return;
    }
};