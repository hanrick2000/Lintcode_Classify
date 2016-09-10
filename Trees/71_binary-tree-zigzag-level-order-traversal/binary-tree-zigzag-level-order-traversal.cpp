/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 16-08-14 22:54
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
        
        vector<vector<int>> result;
        if (root==NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        int flag=1;
        while (!q.empty()) {
            vector<int>list;
            int size = q.size(); // keep the queue size first
            for (int i = 0; i != size; ++i) {
                TreeNode * node = q.front();
                q.pop();
                list.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            if(flag % 2 == 0) reverse(list.begin(),list.end());
            flag++;
            result.push_back(list);
        }
        
        return result;
    }
};