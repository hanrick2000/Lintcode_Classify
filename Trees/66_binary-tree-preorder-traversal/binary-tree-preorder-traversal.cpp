/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-06-27 07:35
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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        
        vector<int>res;
        traverse(root,res);
        
        return res;
}

private:
void traverse(TreeNode *root,vector<int>& ret)
{
       if (root == NULL) {
            return;
        }
        
        ret.push_back(root->val);
        traverse(root->left, ret);
        traverse(root->right, ret);

        return;
}

};

// class Solution {
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: Preorder in vector which contains node values.
//      */
//     vector<int> preorderTraversal(TreeNode *root) {
//         // write your code here
//         vector<int> result;
//         preorder(root, result);
//         return result;
//     }
//     void preorder(TreeNode* node, vector<int>& v){
//         if(!node) return;
//         v.push_back(node->val);
//         if(node->left) preorder(node->left, v);
//         if(node->right) preorder(node->right, v);
//     }
// };
