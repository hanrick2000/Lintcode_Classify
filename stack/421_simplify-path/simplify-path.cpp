/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/simplify-path
@Language: C++
@Datetime: 16-08-26 01:13
*/

// Stack method;

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        string ret,curDir;
        vector<string> allDir;
        path.push_back('/');//In the problem itself: not including the '/';
        
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
            if(curDir.empty()) continue;
            
            else if(curDir == ".")
            {
                curDir.clear();
            }
            
            else if(curDir == "..")
            {
                if(!allDir.empty())
                    allDir.pop_back();
                curDir.clear();
            }
            
            else
            {
                allDir.push_back(curDir);
                curDir.clear();
            }
            
            }
            else
            {
                curDir.push_back(path[i]);
            }
        }
        
        for(int i=0;i<allDir.size();i++)
        {
            ret.append("/" + allDir[i]);
        }
        
        if(ret.empty()) ret ="/";
        return ret;
    }
};