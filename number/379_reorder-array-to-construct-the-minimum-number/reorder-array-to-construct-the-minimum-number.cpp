/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reorder-array-to-construct-the-minimum-number
@Language: C++
@Datetime: 16-08-30 07:59
*/

class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        // Write your code here
        
        sort(nums.begin(), nums.end(), [](const int &i, const int &j) {
            return to_string(i) + to_string(j) < to_string(j) + to_string(i);
        });

        string min_num;
        for (const auto& i : nums) {
            min_num.append(to_string(i));
        }

        int i = 0;
        while (i + 1 < min_num.length() && min_num[i] == '0')  {
            i++;
        }
        
        return min_num.empty() ? "0" : min_num.substr(i);
        
    }
};

//https://github.com/kamyu104/LintCode/blob/master/C++/reorder-array-to-construct-the-minimum-number.cpp