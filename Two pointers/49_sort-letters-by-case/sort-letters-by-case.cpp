/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-letters-by-case
@Language: C++
@Datetime: 16-06-27 06:14
*/

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        
        int left = 0, right = letters.size() - 1;

        while (left < right) {
            
            if (isupper(letters[left])) {
                
                swap(letters[left], letters[right]);
                
                --right;
            } 
            
            else 
            {
                ++left;
            }
        }
    }
};
