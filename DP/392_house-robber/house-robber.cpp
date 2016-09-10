/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: C++
@Datetime: 16-06-25 07:01
*/

// class Solution {
// public:
//     /**
//      * @param A: An array of non-negative integers.
//      * return: The maximum amount of money you can rob tonight
//      */
//     long long houseRobber(vector<int> A) {
//         // write your code here
        
        
        
        
//     }
// };

//Method one: DP

// class Solution {
// public:
//     /**
//      * @param A: An array of non-negative integers.
//      * return: The maximum amount of money you can rob tonight
//      */
//     long long houseRobber(vector<int> A) {
//         if (A.size() <= 1) return A.empty() ? 0 : A[0];
//         vector<long long> dp{A[0], max(A[0], A[1])};// dp{} like: array={a1,a2};
//         for (int i = 2; i < A.size(); ++i) {
//             dp.push_back(max(dp[i - 2] + A[i], dp[i - 1]));
//         }
//         return dp.back();
//     }
// };

//Method two:

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        long long a = 0, b = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i % 2 == 0) {
                a += A[i];
                a = max(a, b);
            } else {
                b += A[i];
                b = max(a, b);
            }
        }
        return max(a, b);
    }
};

//http://www.cnblogs.com/grandyang/p/5445889.html