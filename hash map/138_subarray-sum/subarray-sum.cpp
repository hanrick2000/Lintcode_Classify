/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: C++
@Datetime: 16-08-21 05:25
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        
        map <int,int> has;
        int sum = 0;
        has[0]= -1;
        vector<int>res;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(has.find(sum)!= has.end())
            {
                res.push_back(has[sum]+1);
                res.push_back(i);
                return res;
            }else
            {
                has[sum]=i;
            }
        }
        
      return res;
    }
};