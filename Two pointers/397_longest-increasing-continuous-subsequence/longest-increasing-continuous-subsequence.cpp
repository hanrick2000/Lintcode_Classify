/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 16-06-22 07:35
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
         
         int n = A.size();
         
         if ( n == 1 || n == 0) {
             return n;
         }
         
         int dp;
         int ans = 1;
         
         dp = 1;
         
         for (int i=1; i<=n; ++i) {
             dp = A[i]>=A[i-1]?dp+1:1;
             ans = max(dp, ans);
         }

         dp = 1;
         
         for (int i=n-2; i>=0; --i) {
             dp = A[i]>=A[i+1]?dp+1:1;
             ans = max(dp, ans);
         }
         
         return ans;
    }
};