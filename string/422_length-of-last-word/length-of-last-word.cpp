/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: C++
@Datetime: 16-08-23 03:04
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        
        int n=s.size()-1;
        
        while(n>=0 && s[n]==' ') n--;
        
        int len=0;
        
        while(n>=0 && s[n]!=' ')
        {
            len++;
            n--;
        }
        
        return len;
    }
};