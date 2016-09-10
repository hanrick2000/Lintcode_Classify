/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-06-20 04:48
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        
        if (nums.size() == 0) return 0;

        int len = nums.size();
        int newIndex = 0;
        
        for (int i = 0; i< len; i++) {
            
            if(nums[i] != nums[i-1]||i==0)
            {
                nums[newIndex++] = nums[i];// not equal or equal for only one time, duplicate.
            }
            
            
        }

        return newIndex;
    }
};

//http://www.kancloud.cn/kancloud/data-structure-and-algorithm-notes/72958