/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-09-08 04:29
*/

//Brute force:

// class Solution {
// public:
//     /**
//      * @param A: Given an integers array A
//      * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
//      */
//     vector<long long> productExcludeItself(vector<int> &nums) {
//         // write your code here
        
//         vector<long long> res;
//         long long T;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             T=1;
//             for(int j=0;j<nums.size();j++)
//             {
//             if(i==j) continue;
//             T*=nums[j];
//             }
//             res.push_back(T);
//         }
        
//         return res;
//     }
// };


// class Solution {
// public:
//     /**
//      * @param A: Given an integers array A
//      * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
//      */
//     vector<long long> productExcludeItself(vector<int>& nums) {
//         const int nums_size = nums.size();
//         vector<long long> result(nums_size, 1);
//         if (nums.empty() || nums_size == 1) {
//             return result;
//         }

//         vector<long long> left(nums_size, 1);
//         vector<long long> right(nums_size, 1);
        
//         for (int i = 1; i != nums_size; ++i) {
//             left[i] = left[i - 1] * nums[i - 1];
//             right[nums_size - i - 1] = right[nums_size - i] * nums[nums_size - i];
//         }
        
//         for (int i = 0; i != nums_size; ++i) {
//             result[i] = left[i] * right[i];
//         }

//         return result;
//     }
// };

//Dynamic Programming: 
//1.Left:result[i]=result[i-1]*nums[i - 1];
//2.Right:result[i]*= temp;temp*= nums[i];

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        const int nums_size = nums.size();
        vector<long long> result(nums_size, 1);

        // solve the left part first
        for (int i = 1; i < nums_size; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        // solve the right part
        long long temp = 1;
        for (int i = nums_size - 1; i >= 0; --i) {
            result[i] *= temp;
            temp *= nums[i];
        }

        return result;
    }
};