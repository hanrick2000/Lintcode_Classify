/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 16-08-18 22:00
*/

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code 
     
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1) return 0;
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n,1);
        for(int j=1; j<n; j++) {
            if(obstacleGrid[0][j]==1)//check the first colum;
            //if (obstacleGrid[0][j]==1) dp[0]=0;
                dp[j] = 0;
            else
                dp[j] = dp[j-1];
        }
        
        for(int i=1; i<m; i++) {
            dp[0] = obstacleGrid[i][0]==1 ? 0 : dp[0];//check the first row;if (obstacleGrid[i][0]==1) dp[0]=0;
            for(int j=1; j<n; j++) {
                dp[j] = obstacleGrid[i][j]==1 ? 0 : dp[j-1] + dp[j];//check each element;if (obstacleGrid[i][j]==1) dp[j]=0;
            }
        }
        return dp[n-1];
    }
};