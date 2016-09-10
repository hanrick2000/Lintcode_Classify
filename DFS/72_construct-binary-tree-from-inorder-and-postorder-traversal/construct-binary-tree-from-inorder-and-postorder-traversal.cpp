/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 16-08-29 02:55
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
    return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode *buildTree(vector<int>&inorder, int iLeft,int iRight,vector<int>&postorder,
    int pLeft,int pRight)
    {
        if(iLeft>iRight || pLeft>pRight) return NULL;
        TreeNode * cur = new TreeNode(postorder[pRight]);
        int i=0;
        for(i=iLeft;i<inorder.size();i++)
        {
            if(inorder[i] == cur->val) break;
        }
        cur->left = buildTree(inorder,iLeft,i-1,postorder,pLeft,pLeft+i-iLeft-1);
        cur->right=buildTree(inorder,i+1,iRight,postorder,pLeft+i-iLeft,pRight-1);
        
        return cur;
    }
};

//Good reference:http://www.cnblogs.com/grandyang/p/4296193.html