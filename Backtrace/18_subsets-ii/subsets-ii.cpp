/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/subsets-ii
@Language: C++
@Datetime: 16-07-12 03:26
*/

// class Solution {
// public:
//     /**
//      * @param S: A set of numbers.
//      * @return: A list of lists. All valid subsets.
//      */
// //     vector<vector<int> > subsetsWithDup(const vector<int> &S) {
// //     	vector<int> nums = S;
// //     	std::sort(nums.begin(), nums.end());
    	
// //     	set<vector<int>> ans;
// //     	vector<int> cur;
    	
// //     	for(int i=0;i<=nums.size();++i)
// //     	    dfs(nums, 0, i, 0, cur, ans);
// //     	return vector<vector<int>>(ans.begin(), ans.end());
// //     }
// // private:
// //     void dfs(const vector<int>& S, int d, int k, int s, vector<int>& cur, set<vector<int>>& ans) {
// //         if (d==k) {
// //             ans.insert(cur);
// //             return;
// //         }
        
// //         for(int i=s;i<S.size();++i) {
// //             cur.push_back(S[i]);
// //             dfs(S, d+1, k, i+1, cur, ans);
// //             cur.pop_back();
// //         }
// //     }

//     //Method two:

//     vector<vector<int> > subsetsWithDup(vector<int> &S) {
//         vector<vector<int>> allSets;
//         vector<int> sol;
//         allSets.push_back(sol);
//         sort(S.begin(), S.end());
//         findSubsetsWithDup(S, 0, sol, allSets);
//         return allSets;
//     }
    
//     void findSubsetsWithDup(vector<int> &S, int start, vector<int> &sol, vector<vector<int>> &allSets) {
//         for(int i=start; i<S.size(); i++) {
//             if(i>start && S[i]==S[i-1]) continue;
//             sol.push_back(S[i]);
//             allSets.push_back(sol);
//             findSubsetsWithDup(S, i+1, sol, allSets);
//             sol.pop_back();
//         }
//     }

// };

//http://blog.xiaohuahua.org/2015/09/03/lintcode-subsets-ii/
//DSF排列组合子集问题力推：http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
//[]
// 1,
// 1,2
// 1,2,2
// 2
// 2,2

class Solution {
public:
    
vector<vector<int>>subsetsWithDup(vector<int>&S) {
vector<vector<int>>res;
if(S.empty()) return res;
vector<int>sub;
res.push_back(sub);

sort(S.begin(),S.end());
findSubsetsDup(S,0,sub,res);
return res;

}

void findSubsetsDup(vector<int>&S,int s,vector<int>&sub,vector<vector<int>>&res)
{

    for(int i=s;i<S.size();i++)
    {
        if(i>s && S[i]==S[i-1]) continue;
        sub.push_back(S[i]);
        res.push_back(sub);
        findSubsetsDup(S,i+1,sub,res);
        sub.pop_back();
    }
    
}
    
    
};
