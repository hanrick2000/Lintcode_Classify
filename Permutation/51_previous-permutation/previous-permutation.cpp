/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/previous-permutation
@Language: C++
@Datetime: 16-08-13 01:23
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        
        prev_permutation(nums.begin(), nums.end());
        return nums;
    }
};