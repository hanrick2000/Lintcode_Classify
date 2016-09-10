/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-06-19 22:07
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        
        // write your code here
        
        // Method one:
        
        // if(nums.empty()) return 0;
        // int l = nums.size();
        // sort(nums.begin(),nums.end()); //O(nlog(n))
        // return nums[l/2];
        
        //Method two:
        
        int candidate=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
        if(count==0)
        {
        candidate=nums[i];
        count=1;
        continue;
        }
        else
        {
            if(candidate==nums[i])
            count++;
            else
            count--;
        }
        }
        
        if(count==0) return 0;
        count =0;
        for(int i=0;i<nums.size();i++)
        {
            if(candidate==nums[i])
            count++;
            
        }
        
        return (count>nums.size()/2)? candidate : 0;
    }
    
};
