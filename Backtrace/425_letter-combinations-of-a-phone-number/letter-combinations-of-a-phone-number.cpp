/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/letter-combinations-of-a-phone-number
@Language: C++
@Datetime: 16-08-26 16:44
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string>letterCombinations(string& digits) {
        // Write your code here
        vector<string> res;
        if(digits.empty()) return res;
        string dict[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterCombinationsDFS(digits,dict,0,"",res);
        return res;
    }
    
    void letterCombinationsDFS(string digits, string dict[],int level, string out, vector<string>& res)
    {
        if(level == digits.size()) res.push_back(out);
        else
        {
            string str = dict[digits[level]-'2'];
            for(int i=0;i<str.size();i++)
            {
                out.push_back(str[i]);
                letterCombinationsDFS(digits,dict,level+1,out,res);
//Thinking as:push the first character and has many combinations from remaining characters
//Push first and second characters and has many combinations from the remaining characters;
                out.pop_back();
            }
        }
        
    }
};


//Recursion: http://www.cnblogs.com/grandyang/p/4452220.html

