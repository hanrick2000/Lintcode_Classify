/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-08-21 01:19
*/

// class Solution {
// public:
//     /**
//      * @param key: A String you should hash
//      * @param HASH_SIZE: An integer
//      * @return an integer
//      */
//     int hashCode(string key,int HASH_SIZE) {
//         // write your code here
//     }
// };

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    // long fastPower(int a, int b, int n) {
    //     // write your code here
    //     if(b == 1) return 0;
    //     if(n == 0) return 1;
    //     long c = fastPower(a, b, n/2);
    //     if(n%2)
    //     {
    //         return (((c*c)%b)*(a%b))%b;   
    //     }
    //     return (c*c)%b;
    // }
    
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        // long res = 0;
        // int len = key.length();
        // for(int i=0;i<len;i++)
        // {
        //     res += key[i]*fastPower(33, HASH_SIZE, len-i-1);
        // }
        // return res % HASH_SIZE;
        
        long res = 0;
        for (int i = 0; i < key.size(); i++){
            res = 33 * res + (int)key[i];
            res = res % HASH_SIZE;
        }
        return (int)res;
    }
    
};