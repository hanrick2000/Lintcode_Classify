/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 16-08-18 21:30
*/

// class Solution {
// public:
//     /**
//      * @param grid: a list of lists of integers.
//      * @return: An integer, minimizes the sum of all numbers along its path
//      */
//     int minPathSum(vector<vector<int>> &grid) {
//         // write your code here
        
//         if(grid.empty() || gird[0].empty()) return 0;
        
//         for(int i=1;i<grid.size();i++)
//         {
//             grid[i][0]+=grid[i-1][0];
//             for(int j=1;j<grid[0].size();j++)
//               {
//               grid[0][j]+=grid[0][j-1];   
//               grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
//               }
//         }
        
//         return gird[gird.size()-1][gird[0].size()-1];
//     }
// };

class Solution {

    public:
        // int minPathSum(vector<vector<int> > &grid) {
        //     int m = grid.size();
        //     if (m < 1) 
        //         return 0;
        //     int n = grid[0].size();

        //     vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        //     dp[0][1] = 0;
        //     for (int i = 1; i <= m; ++i)
        //         for (int j = 1; j <= n; ++j)
        //             dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1];
        //     return dp[m][n];
        // }
        
    int minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    if (m < 1) 
        return 0;
    int n = grid[0].size();
    
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;  
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[j] = min(dp[j], dp[j-1]) + grid[i-1][j-1];

    return dp[n];
    }

};

