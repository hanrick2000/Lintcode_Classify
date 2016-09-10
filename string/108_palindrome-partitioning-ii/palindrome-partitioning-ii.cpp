/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning-ii
@Language: C++
@Datetime: 16-08-18 20:56
*/

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        // write your code here
        int n=s.size();
        if(n<=1) return 0;
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]) 
                 isPal[i][j]=true;
            }
        }
        
        vector<int>dp(n+1,INT_MAX);
        dp[0]=-1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(isPal[j][i-1])
                  dp[i]=min(dp[i],dp[j]+1);
            }
        }
        
        return dp[n];
    }
};
/*
整体的思路是一维DP。DP[i]表示长度为i的prefix：s[0: i-1]的min cut数量。
DP[i] = min (DP[j] + 1,DP[i]) ，对所有 0<=j<i，且s[j: i-1]为palindrome。

*/

