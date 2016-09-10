/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 16-08-21 16:27
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    // bool isUnique(string &str) {
    //     // write your code here
        
    //     for(int i=0;i<str.size();i++)
    //     {
    //         for(int j=i+1;j<str.size();j++)
    //         {
    //             if(str[i]==str[j])
    //             return false;
    //         }
            
    //     }
        
    //     return true;
    // }
    
// bool isUnique(string &str) {
//         // write your code here
//         bool cnt[256];
        
//         for(int i=0;i<256;i++)
//         cnt[i]=false;
        
//         if(str.size()<1) return false;
        
//         for(int i=0;i<str.size();i++)
//         {
//             if(cnt[str[i]]) return false;
//             else cnt[str[i]]=true;
//         }
        
//         return true;
//     }

bool isUnique(string &str) {
         // write your code here
         string tmp;
         for (int i=0; i<str.size(); i++) {
             if (tmp.find(str[i])==-1) {
                 tmp.push_back(str[i]);
             } else {
                 return false;
             }
         }
         return true;
     }
};