/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/first-missing-positive
@Language: C++
@Datetime: 16-08-23 02:13
*/

// This is my personal solution

// class Solution {
// public:
//     /**    
//      * @param A: a vector of integers
//      * @return: an integer
//      */
// int firstMissingPositive(vector<int> A) {
//         // write your code here
        
//         if(A.empty()) return 1;
//         sort(A.begin(),A.end());
        
//         int index=0;
        
//         if(A.size()>1)
//         {
//         for(int i=1;i<A.size();i++)
//         {
//             if(A[i]==A[i-1]) continue;
//             A[index++]=A[i-1];
//         }
//         }
        
        
//         int sum1=0,sum2=0;
        
//         for(int i=0;i<A.size();i++)
//         {
//             sum1+=A[i];
//         }
        
        
//         int len=A.size();
        
//         sum2=(A[0]+A[0]+len-1)*len/2;
        
//         if(sum2<0) return 1;
        
//         else if(sum1==sum2) return A[len-1]+1;
        
//         else return sum2-sum1;
        
//     }
// };

// There is the one most popular online;

/*
无序数组的题目如果要O(n)解法往往要用到hash table，但这题要求constant space。所以可以用数组本身作为一个"hash table"：A[0] = 1, A[1] = 2, .... A[n-1] = n。目标是尽可能将数字i放到数组第i-1个位置。

扫描数组中每个数：
1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
*/

class Solution {
public:
    int firstMissingPositive(vector<int> A) {
        int i=0,n=A.size();
        
        while(i<n) {
            if(A[i]!=i+1 && A[i]>=1 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else
                i++;
        }
        for(int i=0; i<n; i++) {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
