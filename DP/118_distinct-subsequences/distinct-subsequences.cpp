/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 16-08-20 23:29
*/

// class Solution {
// public:    
//     /**
//      * @param S, T: Two string.
//      * @return: Count the number of distinct subsequences
//      */
//     int numDistinct(string &S, string &T) {
//         // write your code here
//     }
// };

//http://bangbingsyb.blogspot.com/2014/11/leetcode-distinct-subsequences.html
//4. 计算优化：用滚动数组减少内存消耗。each row as: dp(n+1,1);

class Solution {
public:
    int numDistinct(string S, string T) {
     int n=S.size(),m=T.size();
     vector<int>dp(n+1,1);
     
     for(int i=1;i<=m;i++)
     {
         int upleft = dp[0];
         dp[0]=0; // from the second row;
         for(int j=1;j<=n;j++)
         {
          int temp = dp[j]; 
          dp[j]=dp[j-1];     
          if(S[j-1]==T[i-1]) dp[j]+=upleft; 
          upleft = temp;     
         }
     }
     
     return dp[n];
    }
};
