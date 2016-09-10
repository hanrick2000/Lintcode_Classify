/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/house-robber-iii
@Language: C++
@Datetime: 16-06-25 07:31
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
// class Solution {
// public:
//     /**
//      * @param root: The root of binary tree.
//      * @return: The maximum amount of money you can rob tonight
//      */
//     int houseRobber3(TreeNode* root) {
//         // write your code here
//     }
// };


class Solution {
public:
    int houseRobber3(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode *root) {
        if (!root) return {0, 0};
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res{0, 0};
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = left[0] + right[0] + root->val;
        return res;
    }
};

//http://www.cnblogs.com/grandyang/p/5445661.html