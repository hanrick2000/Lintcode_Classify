/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 16-06-24 04:34
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    // vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    //     // write your code here
    // }
    
    void dfs(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &r, int i){
        if (target<0){
            return;
        }else{
            if (target==0){
                res.push_back(r);
            }else{
                while (i<candidates.size() && target-candidates[i]>=0){
                    r.push_back(candidates[i]);
                    dfs(candidates,target-candidates[i],res,r,i);
                    i++;
                    r.pop_back();
                }
            }
        }
         
    }
    
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if (candidates.size()==0){return res;}
        sort(candidates.begin(),candidates.end());
        vector<int> r;
        dfs(candidates,target,res,r,0);
        return res;
    }
};