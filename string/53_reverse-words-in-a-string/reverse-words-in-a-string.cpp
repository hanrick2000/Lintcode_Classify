/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-06-26 21:05
*/

// #include<string>

// class Solution {
// public:
//     /**
//      * @param s : A string
//      * @return : A string
//      */
//     // string reverseWords(string s) {
//     //     // write your code here
        
//     //     // int st=0;
//     //     // int len=s.size()-1;
        
//     //     // while(s[len]==' ') len--;
//     //     // while(s[st]==' ') st++;
        
//     //     // s=s.substr(st,len-st+1);
        
//     //     int left=0;
//     //     int right=s.size()-1;
//     //     string Rword;
//     //     string Lword;
        
//     //     while(left<=right)
//     //     {
//     //         while(s[right]==' ') right--;
//     //         while(s[left]==' ') left++;
            
//     //         int lt=left;
//     //         int rt=right;
            
//     //         while(s[right]!=' ') 
//     //         right--;
//     //         Rword=s.substr(right,rt-right+1);
//     //         while(s[left]!=' ') 
//     //         left++;
//     //         Lword=s.substr(lt,left-lt+1);
            
//     //         string temp;
//     //         Rword=temp;
//     //         temp=Lword;
//     //         Lword=Rword;
//     //     }
        
//     //     return s;
//     // }
    
    
// };

class Solution {
public:
    string reverseWords(string &s) {
        
        string ret;
        int j = s.size();
        
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i]==' ')
                j = i;
            else if(i==0 || s[i-1]==' ') {
                if(!ret.empty()) ret.append(" ");
                ret.append(s.substr(i, j-i));
                
            }
        }
    return ret;
    }
};