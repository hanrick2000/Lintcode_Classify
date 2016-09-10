/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/k-sum-ii
@Language: C++
@Datetime: 16-08-29 04:03
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int>>kSumII(vector<int> A, int k, int target) {
        // write your code here
        sort(A.begin(),A.end());
        vector<vector<int>>res;
        vector<int>one;
        calc(res,one,A,0,k,target);
        return res;
    }
    
    void calc(vector<vector<int>>&res,vector<int>&one,vector<int> &A,
                int s, int k, int target)
    {
        if(k==0)
        {
            if(target ==0 ) res.push_back(one);
            return;
        }
        
        for(int i=s;i<A.size() && A[i]<=target;i++)
        {
            one.push_back(A[i]);
            calc(res,one,A,i+1,k-1,target-A[i]);
            one.pop_back();
        }
    }            
};
