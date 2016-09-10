/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: C++
@Datetime: 16-08-23 03:44
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char s[], int length) {
        // Write your code here
        if(length == 0) return 0;
        
        int len = length;
        
        for(int i=0;i<length;i++)
        {
            if(s[i]==' ')
            len+=2;
        }
        
        int res = len;
        
        s[len]='\0';
        --len;
        
        for(int i=length-1;i>=0;i--)
        {
            if(s[i] == ' ')
            {
                s[len--]='0';
                s[len--]='2';
                s[len--]='%';
            }
            else 
            s[len--]=s[i];
        }
        
        return res;
    }
};  