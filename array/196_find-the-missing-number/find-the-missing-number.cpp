/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/find-the-missing-number
@Language: C++
@Datetime: 16-08-23 02:18
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        
        int sum1=0,sum2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum1+=i;
            sum2+=nums[i];
        }
        
        sum1+=nums.size(); 
        
        return sum1-sum2;
    }
};