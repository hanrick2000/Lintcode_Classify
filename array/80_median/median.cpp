/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/median
@Language: C++
@Datetime: 16-06-29 04:29
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
int median(vector<int> &nums) {
    // write your code here
    
    sort(nums.begin(),nums.end());
    
    if(nums.size()%2==0) return nums[nums.size()/2-1];
    if(nums.size()%2!=0) return nums[nums.size()/2];
    
}

};
