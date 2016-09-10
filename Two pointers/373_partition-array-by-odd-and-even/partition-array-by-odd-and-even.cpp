/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-06-24 07:51
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        
        for (int left = 0, right = nums.size() - 1; left <= right;) {
            if (nums[left] % 2 == 1) {
                ++left;
            } else if  (nums[right] % 2 == 0) {
                --right;
            } else {
               swap(nums[left++], nums[right--]);
            }
        }
    }
};