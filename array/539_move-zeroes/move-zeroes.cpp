/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 16-06-23 19:42
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // for (int i = 0, j = 0; i < nums.size(); ++i) {
        //     if (nums[i]) {
        //         swap(nums[i], nums[j++]);
        //     }
        // }
        
        int length = nums.size();  
        int cursor = 0;  
        for(int i=0; i<length; i++)  
        {  
            if(nums[i] != 0)  
            {  
                nums[cursor] = nums[i];  
                cursor++;  
            }  
        }  
          
        for(int i=cursor; i<length; i++)  
        {  
            nums[i] = 0;  
        }  

    }
};


// j is for counting  no-zero numbers or the array excluded the zero and the position for the new
// i is for counting  all the numbers in the array

//   1,3,12,0,0,8,9 0 1 0 2
// i 0 1 2  3 4 5 6 7 8 9 10
// j 0 1 2  2 2 2 3 4 4 5 5 6
//          8 9 1 2 0 0 0 0