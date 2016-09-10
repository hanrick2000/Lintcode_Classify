/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-06-23 21:15
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        
        if (root==NULL) return true;
        bool result = true;
        
        maxdepth(result,root);
        
        return result;
    }
private:   
    int maxdepth (bool &IsBalanced, TreeNode* root)
    {
        if(root== NULL) return 0;
        
        int leftDepth=maxdepth (IsBalanced,root->left);
        int rigthDepth=maxdepth (IsBalanced,root->right);
        
        if(abs(leftDepth-rigthDepth)>1)
        {
            IsBalanced=false;
            return INT_MAX;
        }
        
        return max(leftDepth,rigthDepth)+1;
    }
};


// class Solution {
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: True if this Binary tree is Balanced, or false.
//      */
//     bool isBalanced(TreeNode *root) {
//         if (NULL == root) {
//             return true;
//         }

//         bool result = true;
//         maxDepth(root, result);

//         return result;
//     }

// private:
//     int maxDepth(TreeNode *root, bool &isBalanced) {
//         if (NULL == root) {
//             return 0;
//         }

//         int leftDepth = maxDepth(root->left, isBalanced);
//         int rightDepth = maxDepth(root->right, isBalanced);
//         if (abs(leftDepth - rightDepth) > 1) {
//             isBalanced = false;
//             // speed up the recursion process
//             return INT_MAX;
//         }

//         return max(leftDepth, rightDepth) + 1;
//     }
// };