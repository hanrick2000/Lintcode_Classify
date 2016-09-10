/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 16-06-22 07:19
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int m = A.length(), n = B.length();
        vector<vector<int>> D(m+1, vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1] == B[j-1])
                {
                    D[i][j] = D[i-1][j-1] + 1;
                }
                
                else
                {
                    D[i][j] = max(D[i][j-1], D[i-1][j]);
                }
            }
        }
        
        return D[m][n];
    }
};
