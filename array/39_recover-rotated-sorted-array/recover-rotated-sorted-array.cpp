/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/recover-rotated-sorted-array
@Language: C++
@Datetime: 16-08-13 00:21
*/

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int privot=nums.size();
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
            privot=i;
            break;
            }
        }
        
        if(privot==nums.size()) return;
        
        vector<int>arr(privot+1,0);
        
        for(int i=0;i<=privot;i++)
        {
            arr[i]=nums[i];
        }
        
        for(int i=0;i<nums.size()-privot-1;i++)
        {
            nums[i]=nums[privot+i+1];
        }
        
        int index=0;
        
        for(int i=nums.size()-privot-1;i<nums.size();i++)
        {
            nums[i]=arr[index++];
        }
    }
};