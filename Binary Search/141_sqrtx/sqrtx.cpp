/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: C++
@Datetime: 16-08-21 06:37
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x<0) return -1;
        
        long long l=0,r=x/2+1;
        
        while(l<=r)
        {
           long long mid = (r+l)/2;
           long long tmp = mid*mid-x;
           
           if(tmp==0) 
              return mid;
           else if(tmp>0) 
           {
              r=mid-1;
           }
           else{
             l=mid+1;
           }
        }
        
         return r;
    }
};