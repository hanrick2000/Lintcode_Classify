/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/validate-binary-search-tree
@Language: C++
@Datetime: 16-08-17 17:51
*/

// /**
//  * Definition of TreeNode:
//  * class TreeNode {
//  * public:
//  *     int val;
//  *     TreeNode *left, *right;
//  *     TreeNode(int val) {
//  *         this->val = val;
//  *         this->left = this->right = NULL;
//  *     }
//  * }
//  */
// class Solution {
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: True if the binary tree is BST, or false
//      */
//     bool isValidBST(TreeNode *root) {
//         // write your code here
        
//         bool flag=true;
        
//         BST_Traversal(root,flag);
//         return flag;
//     }
    
//     void BST_Traversal(TreeNode *root,bool flag)
//     {
//         if(root->left==NULL && root->right==NULL) return;
        
//         if(root->left==NULL && root->right->val<root->val)
//         {
//         flag=false;
//         return;
//         }
        
//         if(root->right==NULL && root->left->val>root->val)
//         {
//         flag=false;
//         return;
//         }
        
//         if(root->left!=NULL && root->right!=NULL && (root->left->val>root->val || root->right->val<root->val) )
//         {
//         flag=false;
//         return;
//         }
        
//         BST_Traversal(root->left,flag);
//         BST_Traversal(root->right,flag);
//     }
// };

//Note: the value is not left and right; but left and root or root and right;
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;

        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool helper(TreeNode *root, long long lower, long long upper) {
        if (root == NULL) return true;

        if (root->val <= lower || root->val >= upper) return false;
        bool isLeftValidBST = helper(root->left, lower, root->val);
        bool isRightValidBST = helper(root->right, root->val, upper);

        return isLeftValidBST && isRightValidBST;
    }
};

