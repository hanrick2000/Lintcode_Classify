/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: C++
@Datetime: 16-08-17 17:20
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        
        if(m==0 || A.empty()) return 0;
        
        int n=A.size();
        int f[m+1];
        
        for(int j=0;j<=m;j++)
        f[j]=0;
        
        for(int i=1;i<=n;i++)
        {
          for(int j=m;j>=1;j--)
          {
            if(j>=A[i-1])  
             f[j] = max(f[j-A[i-1]]+V[i-1],f[j]);
          }
        }
        return f[m];
    }
};