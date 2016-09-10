/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-08-25 20:17
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        // Write your code here
        long res=0;
        while(n)
        {
            res = n%10 + res*10 ;
            n/=10;
        }
        return (res<INT_MIN||res>INT_MAX)? 0 : res;
    }
};

// class Solution {
// public:
//     /**
//      * @param n the integer to be reversed
//      * @return the reversed integer
//      */
//     int reverseInteger(int n) {
//         long long res = 0;
//         while (n != 0) {
//             res = 10 * res + n % 10;
//             n /= 10;
//         }
//         return (res < INT_MIN || res > INT_MAX) ? 0 : res;
//     }
// };