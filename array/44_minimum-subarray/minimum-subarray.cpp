/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-06-19 23:46
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        
        int min_sum = INT_MAX;
        int sum = 0;
        
        for(auto n : nums)
        {
            sum += n;
            min_sum = min(min_sum, sum);
            if(sum>0) sum=0;
        }
        
        return min_sum;
    }
};

/*
1. Initialize sum = 0, min_sum = MAX_INT
2. for each num n, sum + n, check sum with min_sum
3. if sum > 0, no need to keep it, reset sum to 0.
*/

//                1  -1 -2  1  -9   21  -13
// sum      0     1  -1 -3 -2  -11  10  -13
// min_sum  max   1  -1 -3 -3  -11 -11  -11
// sum      0     0  -1 -3 -2  -11  0   -13