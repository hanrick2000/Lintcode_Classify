/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-08-30 03:22
*/

//c &= (c-1) : 消去bits最右边的那个1；
//a^b : 异或性质－－a和b有多少不同的位数 a^b之后就有多少个不同的1

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int cnt = 0;
        for(int c=a^b;c!=0;c &= c-1)
          cnt++;
        return cnt;
    }
};