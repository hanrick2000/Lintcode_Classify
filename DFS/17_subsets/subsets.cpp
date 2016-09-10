/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/subsets
@Language: C++
@Datetime: 16-06-24 22:44
*/

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int> > result;
//         if (nums.empty()) return result;

//         sort(nums.begin(), nums.end());
//         vector<int> list;
//         dfs(nums, 0, list, result);

//         return result;
//     }

// private:
//     void dfs(vector<int>& nums, int pos, vector<int> &list,
//              vector<vector<int> > &ret) {

//         ret.push_back(list);

//         for (int i = pos; i < nums.size(); ++i) {
//             list.push_back(nums[i]);
//             dfs(nums, i + 1, list, ret);
//             list.pop_back();
//         }
//     }
// };

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> allSets;
        vector<int> sol;
        allSets.push_back(sol);
        sort(S.begin(),S.end());
        findSubsets(S, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsets(vector<int> &S, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        for(int i=start; i<S.size(); i++) {
            sol.push_back(S[i]);
            allSets.push_back(sol);
            findSubsets(S, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};

//Backtrace:http://www.code123.cc/docs/leetcode-notes/backtracking/subsets.html