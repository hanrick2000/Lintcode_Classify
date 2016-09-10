/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 16-08-23 03:20
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
// class Solution {
// public:
//     /**
//      * @param root: a TreeNode, the root of the binary tree
//      * @return: nothing
//      */
//     void invertBinaryTree(TreeNode *root) {
//         // write your code here
        
//         if(root==NULL) return;
        
//         TreeNode *temp = root->left;
//         root->left =root->right;
//         root->right =temp;
        
//         invertBinaryTree(root->left);
//         invertBinaryTree(root->right);
//     }
// };

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (root == NULL) return NULL;

//         TreeNode *temp = root->left;
//         root->left = invertTree(root->right);
//         root->right = invertTree(temp);

//         return root;
//     }
// };


class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == NULL) return;
       //We know the (TreeNode *) is level-order traversal;
       //So that we could use a queue in this problem
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            // pop out the front node
            TreeNode *node = q.front();
            q.pop();
            // swap between left and right pointer
            swap(node->left, node->right);
            // push non-NULL node
            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);
        }
    }
};