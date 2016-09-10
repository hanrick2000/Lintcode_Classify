/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/partition-array
@Language: C++
@Datetime: 16-06-24 07:26
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        
        // My original method:
        
        // if(nums.empty()) return 0;
        
        // int left=0;
        // int right=nums.size()-1;
        
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]<k) 
        //     swap(nums[left++],nums[i]);
        //     else 
        //     swap(nums[right--],nums[i]);
        // }
        
        // if(left==nums.size()-1) return nums.size();
        
        // return left;
        
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] < k) {
                ++left;
            } else if (nums[right] >= k) {
                --right;
            } else {
               swap(nums[left++], nums[right--]);
            }
        }
        
        return left;
    }
};