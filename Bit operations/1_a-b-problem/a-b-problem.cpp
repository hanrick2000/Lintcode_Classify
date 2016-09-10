/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 16-06-18 22:32
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        
    // a=0010 1111  0000 1110  0100 1100  0100 1000  0100 1000   0101 1000
    // b=0010 0001  0100 0010  0000 0100  0000 1000  0001 0000
//   a^b=0000 1110  0100 1100  0100 1000  0100 0000  0101 1000
//   a&b=0010 0001  0000 0010  0000 0100  0000 1000  0000 0000
//a&b<<1=0100 0010  0000 0100  0000 1000  0001 0000  0000 0000
    while (b != 0) {
            int _a = a ^ b;//no carry addition representation
            int _b = (a & b) << 1;//carry representation 
            a = _a;
            b = _b;
    }
        return a;

    }
};

// Unsigned and signed number convert: 5-7(signed):0101+1001(2^4-9=7)(-7)
//http://stackoverflow.com/questions/7349689/c-how-to-print-using-cout-the-way-a-number-is-stored-in-memory