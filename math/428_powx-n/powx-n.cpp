/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-06-25 22:32
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        // Write your code here
        if(n==0) return 1.0;
        
        double ans=1.0;
        
        int sign=1;
        
        if(n<0) 
        {
         sign=0;
         n=-n;
        }
        while(n)
        {
            ans*=x;
            n--;
        }
        
        return sign==1 ? ans : 1.0/ans;
    }
};