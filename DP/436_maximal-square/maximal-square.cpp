/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/maximal-square
@Language: C++
@Datetime: 16-08-26 15:57
*/

//--DP:O(n^2);

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>>&matrix) {
        // write your code here
        if(matrix.empty()||matrix[0].empty()) return 0;
        int M = matrix.size(),N=matrix[0].size(),res=0;
        vector<vector<int>>dp(M,vector<int>(N,0));
        
        for(int i=0;i<M;i++)
        {
            if(matrix[i][0] == 1)
            {
            dp[i][0] = 1;
            res = 1;
            }
        }
        
        for(int j=0;j<N;j++)
        {
            if(matrix[0][j] == 1)
            {
            dp[0][j] = 1;
            res = 1;
            }
        }
        
        for(int i=1;i<M;i++)
        {
            for(int j=1;j<N;j++)
            {
                if(matrix[i][j] == 1)
                  dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                res = max(res,dp[i][j]);
            }
        }
        
        return res * res ;
    }
};

//Good reference: http://yucoding.blogspot.com/2015/10/leetcode-question-maximal-square.html
//http://www.cnblogs.com/easonliu/p/4548769.html