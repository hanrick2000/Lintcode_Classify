/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/minimum-adjustment-cost
@Language: C++
@Datetime: 16-08-17 16:20
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        
        //dp[i][j]: the cost to adjust the A[i] to become j;
        // j is from 0 -100; according to the problem;
        //Equation: dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(A[i]-j))
        //k:A[i-1] to the adjustment k and 
        //the range is:(max(0,j-target),min(100,j+target))
        //|k|<=100 && |j-k|<=target and thus the range comes out;
        
        if(A.empty()) return 0;
        vector<vector<int>>dp(A.size(),vector<int>(101,INT_MAX));
        
        for(int i=0;i<=100;i++)
        {
        dp[0][i]=abs(A[0]-i);
        }
        
        for(int i=1;i<A.size();i++)
        {
            for(int j=0;j<=100;j++)
            {
                for(int k=max(0,j-target);k<=min(100,j+target);k++)
                  dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(A[i]-j));
            }
            
        }
        
        int res=INT_MAX;
        for(int i=0;i<=100;i++)
        {
        res=min(res,dp[A.size()-1][i]);
        }
        
        // The last round we have gotten 101 outcomes for the dp[A.size()-1][j];
        // Thus, we should also find the min cost towards the 101 status;
        
        return res;
    }
};

// class Solution {
// public:
//     /**
//      * @param A: An integer array.
//      * @param target: An integer.
//      */
//     int MinAdjustmentCost(vector<int> A, int target) {
//         // write your code here
//         if (A.empty()) return 0;
//         vector<vector<int>> dp(A.size(), vector<int>(101, INT_MAX));
//         for (int i = 0; i <= 100; ++i) {
//             dp[0][i] = abs(A[0] - i);
//         }
//         for (int i = 1; i < A.size(); ++i) {
//             for (int j = 0; j <= 100; ++j) {
//                 for (int k = max(0, j - target); k <= min(100, j + target); ++k)
//                     dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(A[i] - j));
//             }
//         }
//         int res = INT_MAX;
//         for (int i = 0; i <= 100; ++i) {
//             res = min(res, dp[A.size()-1][i]);
//         }
//         return res;
//     }
// };