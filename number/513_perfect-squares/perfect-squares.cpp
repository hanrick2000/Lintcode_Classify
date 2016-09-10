/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/perfect-squares
@Language: C++
@Datetime: 16-08-28 00:04
*/

/*
四平方和定理(Lagrange's Four-Square Theorem)：
所有自然数至多只要用四个数的平方和就可以表示。
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @return an integer
     */
    int numSquares(int n) {
        // Write your code here
        while(n%4 == 0) n/=4;
    //如果一个数除以8余7的话，那么肯定是由4个完全平方数组成
        if(n%8 == 7) return 4;
    //下面我们就来尝试的将其拆为两个平方数之和，如果拆成功了那么就会返回1或2，因为其中一个平方数可能为0. 
        for(int a=0;a*a<=n;a++)
        {
            int b = sqrt(n-a*a);
            if(a*a + b*b == n)
            return !!a + !!b;
//感叹号!表示逻辑取反，那么一个正整数逻辑取反为0，再取反为1,所以用两个感叹号!!的作用就是看a和b是否为正整数，都为正整数的话返回2;
//只有一个是正整数的话返回1;            
        }
        return 3;
    }
};

//Some other DP solutions:http://www.cnblogs.com/grandyang/p/4800552.html