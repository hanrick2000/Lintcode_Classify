/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-06-22 07:05
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        
        int m = A.size();
        int n = B.size();
         if (m == 0 || n == 0) {
             return 0;
         }
         int ans = 0;
         for (int i = 0; i < m; ++i) {
             for (int j = 0; j < n; ++j) {
                 int len = 0;
                 while (i + len < m && j + len < n && A[i + len] == B[j + len]) {
                     len ++;
                     ans = max(ans, len);
                 }
             }
         }
         return ans;
    }
};
