/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/house-robber-ii
@Language: C++
@Datetime: 16-06-25 07:11
*/

// class Solution {
// public:
//     /**
//      * @param nums: An array of non-negative integers.
//      * return: The maximum amount of money you can rob tonight
//      */
//     int houseRobber2(vector<int>& nums) {
//         // write your code here
//     }
// };

//Method one: DP;

// class Solution {
// public:
//     /**
//      * @param nums: An array of non-negative integers.
//      * return: The maximum amount of money you can rob tonight
//      */
//     int houseRobber2(vector<int>& nums) {
//         if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
//         vector<int> a = nums, b = nums;
//         a.erase(a.begin()); b.pop_back();
//         return max(rob(a), rob(b));
//     }
//     int rob(vector<int> &nums) {
//         if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
//         vector<int> dp{nums[0], max(nums[0], nums[1])};
//         for (int i = 2; i < nums.size(); ++i) {
//             dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
//         }
//         return dp.back();
//     }
// };


//Method two: common;

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int> &nums, int left, int right) {
        int a = 0, b = 0;
        for (int i = left; i < right; ++i) {
            int m = a, n = b;
            a = n + nums[i];
            b = max(m, n);
        }
        return max(a, b);
    }
};

//http://www.cnblogs.com/grandyang/p/5445914.html