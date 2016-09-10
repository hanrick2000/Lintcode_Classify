/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-06-20 03:31
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
int majorityNumber(vector<int> nums){
        
        // write your code here
         int num1 = 0, num2 = 0;
         int ret1 = 0, ret2 = 0;
         
         for (int i = 0; i < nums.size(); i++) {
             if (num1 != 0 && ret1 == nums[i]) {
                 num1++;
             } else if (num2 != 0 && ret2 == nums[i]) {
                 num2++;
             } else if (num1 != 0 && num2 != 0) {
                 num1--; 
                 num2--;
             } else if (num1 == 0) {
                 num1 = 1;
                 ret1 = nums[i];
             } else {
                 num2 = 1;
                 ret2 = nums[i];
             }
         }
         
         int count1 = 0, count2 = 0;
         
         for (int i = 0; i < nums.size(); i++) {
             if (ret1 == nums[i]) {
                 count1++;
             } else if (ret2 == nums[i]) {
                 count2++;
             }
         }
         
         if (count1 > count2) {
             return ret1;
         } else {
             return ret2;
         }
    }
    
};

//和上一道题异曲同工，由于多于数组长度三分之一的数可能有两个，那么我们设置两个计数器，找出这两
//数；再用两个计数器重新计数，找出个数更多的那个数，就是所求。
