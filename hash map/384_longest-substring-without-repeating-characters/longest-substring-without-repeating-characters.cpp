/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-substring-without-repeating-characters
@Language: C++
@Datetime: 16-08-25 02:32
*/

/*
Set two pointers, i,j, scan the string from the start to the end. Set a table to store if the character has occurred.
,  . Then table[s[i]]=false; i++; If, table[s[j]]=true; j++; 
*/


class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;
        
        int i=0,j=0;
        int maxl = 0;
        map<char,bool>table;
        
        while((i<s.size())&&(j<s.size()))
        {
            if(table[s[j]] == false)// s[j] has not occurred in S[i..j-1]
            {
                table[s[j]] = true;
                maxl = max(maxl,j-i+1);
                //compute current length and compare to the max length
                j++;
            }
            else if (table[s[j]]==true)// s[j] has occurred in S[i..j-1]
            {
              maxl = max(maxl,j-i);
              //compute current length and compare to the max length
              table[s[i]] = false;    
              i++;    
            }
        }
        return maxl;
    }
};

//http://yucoding.blogspot.com/2013/01/leetcode-question-45-longest-substring.html