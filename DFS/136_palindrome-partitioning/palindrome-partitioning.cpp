/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: C++
@Datetime: 16-08-18 20:46
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        int n=s.size();
        vector<vector<string>>ret;
        vector<string>sol;
        vector<vector<bool>>isPal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--)
        {
          for(int j=i;j<n;j++)
            {
             if((i+1>=j-1||isPal[i+1][j-1]) && s[i]==s[j])    
                isPal[i][j]=true;
            }
        }
        
        findPartitions(s,0,isPal,sol,ret);
        return ret;
    }
    
    void findPartitions(string &s,int start,vector<vector<bool>>&isPal,vector<string> &sol,vector<vector<string>> &ret)
    {
        if(start == s.size())
        {
            ret.push_back(sol);
            return;
        }
        
        for(int i=start;i<s.size();i++)
        {
            if(isPal[start][i])
            {
                int len=i-start+1;
                sol.push_back(s.substr(start,len));
                findPartitions(s,i+1,isPal,sol,ret);
                sol.pop_back();
            }
        }
        
    }
    
};

