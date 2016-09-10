/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 16-08-23 04:12
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>&A) {
        // write your code here
        
        int n=A.size();
        if(n<=0) return 0;
        
        int ret,curMax,curMin;
        
        ret = curMax = curMin = A[0];
        
        for(int i=1;i<n;i++)
        {
            int temp = curMax;
            curMax = max(max(curMax*A[i],curMin*A[i]),A[i]);
            curMin = min(min(temp*A[i],curMin*A[i]),A[i]);
            ret=max(ret,curMax);
        }
        
        return ret;   
    }
};


//[LeetCode] Maximum Subarray : 
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
/*
典型的DP题：
1. 状态dp[i]：以A[i]为最后一个数的所有max subarray的和。
2. 通项公式：dp[i] = dp[i-1]<=0 ? dp[i] : dp[i-1]+A[i]
3. 由于dp[i]仅取决于dp[i-1]，所以可以仅用一个变量来保存前一个状态，而节省内存。
*/
// class Solution {
// public:
//     int maxSubArray(int A[], int n) {
//         if(n<=0) return 0;
//         int maxSum = A[0], curSum = A[0];
//         for(int i=1; i<n; i++) {
//             curSum =  curSum<=0 ? A[i] : A[i]+curSum;
//             maxSum = max(maxSum,curSum);
//         }
//         return maxSum;
//     }
// };

/*
Maximum Subarray那题的变种。由于正负得负，负负得正的关系。以A[i]结尾的max product subarray同时取决于以A[i-1]结尾的max / min product subarray以及A[i]本身。因此，对每个i，需要记录min/max product两个状态：

max_product[i] = max(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
min_product[i] = min(max_product[i-1]*A[i], min_product[i-1]*A[i], A[i]) 
*/

//Good reference : http://bangbingsyb.blogspot.com/2014/11/leetcode-maximum-product-subarray.html