/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/word-break
@Language: C++
@Datetime: 16-06-25 06:34
*/

// class Solution {
// public:
//     /**
//      * @param s: A string s
//      * @param dict: A dictionary of words dict
//      */
//     // bool wordBreak(string s, unordered_set<string> &dict) {
//     //     // write your code here
        
//     //     int l=s.length();
        
//     //     vector<bool>isMatch(l+1,false);
        
//     //     isMatch[0]=true;
        
//     //     for(int i=1;i<=l;i++)
//     //     {
//     //         for(int j = i - 1; j >= 0; j--)
//     //         {
//     //         if(isMatch[j] && dict.find(s.substr(j,i-j))!=dict.end())
//     //         {
//     //             isMatch[i]=true;
//     //             break;
//     //         }
            
//     //         }
//     //     }
        
//     //     return isMatch[l];
        
//     // }

// };

class Solution {
public:
    /** * @param s: A string s * @param dict: A dictionary of words dict */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here

        int len=s.size();

        if(len==0){
            return true;
        }

        if(dict.size()==0){
            return false;
        }

        int maxLen=0;
        for(string str:dict){
            if(str.size()>maxLen){
                maxLen=str.size();
            }
        }

        vector<bool> res(len+1,false);
        res[0]=true;

        for(int i=1;i<=len;i++){
            for(int j=i-1;j>=0;j--){

                if(i-j>maxLen){
                    break;
                }

                bool flag=res[j]&& dict.find(s.substr(j,i-j))!=dict.end();
                if(flag){
                    res[i]=true;
                    break;
                }
            }
        }

        return res[len];
    }
};