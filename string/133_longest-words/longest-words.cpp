/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: C++
@Datetime: 16-08-23 03:11
*/

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        
        if(dictionary.size()<=1) return dictionary;
        
        vector<string> res;
        
        int max_len=0,cur_len;
        
        for(int i=0;i<dictionary.size();i++)
        {
            cur_len = dictionary[i].size();
            
            if(cur_len<max_len) continue;
            
            if(cur_len>max_len)
            {
                res.clear();
                max_len=cur_len;
            }
            res.push_back(dictionary[i]);
        }
        
        return res;
    }
};