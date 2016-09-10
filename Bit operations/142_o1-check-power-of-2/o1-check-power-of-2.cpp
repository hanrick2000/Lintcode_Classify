/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: C++
@Datetime: 16-08-21 07:16
*/

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        
        if(n<1) return false;

        return (n&(n-1))==0;
        
    }
};