/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 16-08-29 07:18
*/

// -- Recrusion Method;

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(n==1) return a%b;
        else if(n==0)
          return 1%b;
        else if(n<0)
          return -1;
          
        //(a*b) % p = ((a%p) * (b%p)) % p; 
        long long product = fastPower(a,b,n/2);
        product = (product*product)%b;
        
        if(n%2==1) 
          product = (product*a)%b;
        
        return (int)product;   
    }
    
};