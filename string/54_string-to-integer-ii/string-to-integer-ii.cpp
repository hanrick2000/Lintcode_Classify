/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: C++
@Datetime: 16-09-06 08:40
*/

// class Solution {
// public:
//     /**
//      * @param str: A string
//      * @return An integer
//      */
//     int atoi(string str) {
//         // write your code here
//     int res = 0; // Initialize result
//     // Iterate through all characters of input string and
//     // update result
//     for (int i = 0; str[i] != '\0'; ++i)
//         res = res*10 + str[i] - '0';
//     // return result.
//     return res;
//     }
// };
//The above function doesnât handle negative numbers. Following is a simple extension to handle negative numbers.

// class Solution {
// public:
//     /**
//      * @param str: A string
//      * @return An integer
//      */
//     int atoi(string str) {
//         // write your code here
        
//     int res = 0;  // Initialize result
//     int sign = 1;  // Initialize sign as positive
//     int i = 0;  // Initialize index of first digit
      
//     // If number is negative, then update sign
//     if (str[0] == '-')
//     {
//         sign = -1;  
//         i++;  // Also update index of first digit
//     }
      
//     // Iterate through all digits and update the result
//     for (; str[i] != '\0'; ++i)
//         res = res*10 + str[i] - '0';
    
//     // Return result with sign
//     return sign*res;
    
//     }
// };
//The above implementation doesnât handle errors. What if str is NULL or str contains non-numeric characters. Following implementation handles errors.

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
int atoi(string str)
{
    //pass the initial space
              int i = 0;
              unsigned long long res = 0;
              while (str[i] == ' ')i++;

              //parse the first non space char
              if (str[i] != '+' && str[i] != '-' && isdigit(str[i]) == 0)return 0;
              bool neg = false;
              if (str[i] == '+') { neg = false; i++; }
              else if (str[i] == '-') { neg = true; i++; }
              else neg = false;
              //parse the char followered by + -
              if (isdigit(str[i]) == 0)return 0;
              else {
                     while (isdigit(str[i])){
                           res = res * 10 + str[i] - '0';
                           if (res>INT_MAX)return neg ? INT_MIN : INT_MAX;
                           i++;
                     }
              }
              return neg ? -res : res;
}

};



