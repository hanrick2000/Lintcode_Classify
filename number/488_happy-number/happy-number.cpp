/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-08-27 15:31
*/

//关于非快乐数有个特点，循环的数字中必定会有4
// class Solution {
// public:
//     /**
//      * @param n an integer
//      * @return true if this is a happy number or false
//      */
//     bool isHappy(int n) {
//         // Write your code here
        
//         while(n!=1 && n!=4)
//         {
//             int t=0;
//             while(n)
//             {
//                 t+=(n%10) * (n%10);
//                 n/=10;
//             }
//             n = t;
//         }
        
//         return n == 1;
//     }
// };


// -- Classic solution;

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        set<int> s;
        
        while(n!=1)
        {
            int t = 0;
            while(n)
            {
                t+= (n%10) * (n%10);
                n/=10;
            }
            n=t;
            if(s.count(n)) break;
            else 
              s.insert(n);
        }
        
        return n == 1;
    }
};