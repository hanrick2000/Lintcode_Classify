/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-palindromic-substring
@Language: C++
@Datetime: 16-08-18 20:24
*/

// class Solution {
// public:
//     /**
//      * @param s input string
//      * @return the longest palindromic substring
//      */
//     string longestPalindrome(string& s) {
//         // Write your code here
        
//         int n=s.size();
//         int start=0,maxlen=1;// one single is also a palindrome
        
//         int i,j,k;
        
//         for(i=0;i<n;i++)
//         {
//             j=i,k=i+1;//Even length;
//             while(j>=0 && k<n)
//             {
//                 if(s[j]!=s[k]) break;
//                 if(k-j+1>maxlen)
//                 {
//                     start=j;
//                     maxlen=k-j+1;
//                 }
//                 j--;
//                 k++;
//             }
            
//             j=i-1,k=i+1;//odd length;
//             while(j>=0 && k<=n-1)
//             {
//                 if(s[j]!=s[k]) break;
//                 if(k-j+1>maxlen)
//                 {
//                     start=j;
//                     maxlen=k-j+1;
//                 }
//                 j--;
//                 k++;
//             }
//         }
        
//         return s.substr(start,maxlen);
//     }
// };

/*
定义bool isPal[i][j]表示s[i:j]是否为回文，isPal[i][j] = true需要满足两个条件: 
1. s[i] == s[j]
2. i+1>j-1或 isPal[i+1][j-1] == true (即s[i+1 : j-1]是回文)
*/

//---- Dp solution : two-demensions;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1) return s; 
        int start = 0, maxLen = 1, n = s.size();
        bool isPal[1000][1000] = {false};
        
        for(int i=n-1; i>=0; i--) {
            for(int j=i; j<n; j++) {
                if((i+1>j-1 || isPal[i+1][j-1]) && s[i]==s[j]) {
                    isPal[i][j] = true;
                    if(j-i+1>maxLen) {
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
    }
};