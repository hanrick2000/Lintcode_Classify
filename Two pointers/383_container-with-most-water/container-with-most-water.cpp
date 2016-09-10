/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: C++
@Datetime: 16-08-25 02:32
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &height) {
        // write your code here
        
        int res = 0, left = 0, right = height.size()-1;
        
        while(left<right)
        {
            res = max(res,min(height[left],height[right])*(right-left));
            if(height[left]<height[right]) left++;
            else
              right--;
        }
        
        return res;
    }
};


// Taken from the : http://www.cnblogs.com/grandyang/p/4455109.html
//Another good reference:http://bangbingsyb.blogspot.com/2014/11/leetcode-container-with-most-water.html