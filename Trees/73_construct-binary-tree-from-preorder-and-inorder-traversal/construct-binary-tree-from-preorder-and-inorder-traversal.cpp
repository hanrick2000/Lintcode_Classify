/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: C++
@Datetime: 16-08-29 03:31
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    // TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    //     // write your code here
    // }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
    return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    
    TreeNode *buildTree(vector<int>&preorder, int preLeft,int preRight,vector<int>&inorder,
    int iLeft,int iRight)
    {
        if(iLeft>iRight || preLeft>preRight) return NULL;
        int i=0;
        for(i=iLeft;i<inorder.size();i++)
        {
            if(inorder[i] == preorder[preLeft]) break;
        }// Find the root node in the inorder : preLeft is the root
        TreeNode * cur = new TreeNode(preorder[preLeft]);
 cur->left = buildTree(preorder,preLeft+1,preLeft+i-iLeft,inorder,iLeft,i-1);
 cur->right=buildTree(preorder,preLeft+i-iLeft+1,preRight,inorder,i+1,iRight);
 // The left is the root node minus 1 and the right is the roow node plus 1
 // The length of the subtrees are the same in both preorder and inorder
 // Here the length is: i-iLeft+1
 // we the the first node in the preorder as the root and using the i+1th(i)
 // as the root in the inorder;
 // Thus the next left in preorder : preLeft+1 ~ preLeft-1+(i-iLeft+1);
 //The next left in preorder:iLeft~i-1;
 // The next right in preorder :(preLeft-1+(i-iLeft+1))+1 ~ preRight;
 // The next right in inorder  :i+1 ~ iRight;
        return cur;
    }
};

//Good reference:http://www.cnblogs.com/grandyang/p/4296500.html