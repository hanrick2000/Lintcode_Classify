/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 16-08-17 17:13
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
/*
这题一次性通过率很低(20%)，必须要优化空间复杂度！时间复杂度O(n m)应该差不多了，但是空间复杂度可以优化到O(m)。因为DP的记忆深度只有2.

状态定义和转移方程同经典的背包问题：定义f(i, j)表示前i个物品放入大小为j的空间里能够占用的最大体积，则递推式为：

f(i, j) = max( f(i-1, j), f(i-1, j-A[i-1]) + A[i-1] )

递推的时候，对每个i，从后往前计算即可，这样就用一维数组就行了。
*/
//For each i(A[i-1]): you can choose to put it in or not
// f(i-1,j):put the previous i-1 only
// f(i-1,j-A[i-1])+A[i-1]: put the item i and only leave the space j-A[i-1] for the previous i-1 items; 
//Thus f(i,j)=max(f(i-1,j),f(i-1,j-A[i-1])+A[i-1]);

    int backPack(int m, vector<int> A) {
        // write your code here
        
        if(m==0 || A.empty()) return 0;
        
        int n=A.size();
        int f[m+1];
        
        for(int j=0;j<=m;j++)
        f[j]=0;
        
        for(int i=1; i<=n;i++)
        {
          for(int j=m;j>=1;j--)
          {
            if(j>=A[i-1])  
             f[j] = max(f[j-A[i-1]]+A[i-1],f[j]);
          }
        }
        return f[m];
    }
};