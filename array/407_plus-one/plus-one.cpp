/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-08-25 19:30
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        
        int carry=1;
        vector<int> res;
        
        // carry=(digits[digits.size()-1]+1)/10;
        // digits[digits.size()-1] = (digits[digits.size()-1]+1)%10;
        
        
        for (int i=digits.size()-1;i>=0;i--) 
        {
            int temp = digits[i]+carry;
            carry=(temp)/10;
            digits[i] = (temp)%10;
        }
        
        if(carry == 0) res = digits;
        else if (carry == 1)
        {
            res.push_back(1);
            
            for(int i=0;i<digits.size();i++)
            {
                res.push_back(digits[i]);
            }
        }
        
        return res;
    }
};