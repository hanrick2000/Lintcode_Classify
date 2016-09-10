/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 16-09-06 23:44
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        
        long long count=0;
        
        while(n>0)
        {
            // long long k;
            // k=n/5;
            n=n/5;
            // from n/5 to n, the number of '5' total
            count+=n;
            // each time, and want to gain the 1-n, the number of '5' total
           // n=k;
        }
        
        return count;
    }
};
