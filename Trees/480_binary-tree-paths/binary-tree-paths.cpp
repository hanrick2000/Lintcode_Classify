/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-06-25 05:28
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

string int2string(int x){
        stringstream ss;
        ss << x;
        string tmp;
        ss >> tmp;
        return tmp;
    }

void backtrack(TreeNode* root, vector<int>& path, vector<string>& ans){
        if(root == NULL){
            return;
        }else if(root->left == NULL && root->right == NULL){
            string tmp = "";
            for(int i = 0; i < path.size(); ++i){
                tmp += int2string(path[i]);
                tmp += "->";
            }
            tmp += int2string(root->val);
            ans.push_back(tmp);
            return;
        }
        if(root->left != NULL){
            path.push_back(root->val);
            backtrack(root->left, path, ans);
            path.pop_back();
        }
        if(root->right != NULL){
            path.push_back(root->val);
            backtrack(root->right, path, ans);
            path.pop_back();
        }
    }
    
vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<string> ans;
        backtrack(root, path, ans);
        return ans;
}
    
};