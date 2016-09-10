/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-07-12 02:21
*/

// class Solution {
// public:
//     /**
//      * Returns a index to the first occurrence of target in source,
//      * or -1  if target is not part of source.
//      * @param source string to be scanned.
//      * @param target string containing the sequence of characters to match.
//      */
     
//     // int strStr(const char *source, const char *target) {
//     //     // write your code here
//     //     return -1;
//     // }
    
//     int strStr(const char *source, const char *target) {
//         if (source != nullptr && target != nullptr) {
            
//             const string src(source), tgt(target);
            
//             for (int i = 0; i < src.length() - tgt.length() + 1; ++i) {
//                 if (src.substr(i, tgt.length()) == tgt) {
//                     return i;
//                 }
//             }
            
//         }
//         return -1;
//     }

// };

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    
int strStr(const char *source, const char *target) {
 
  if(source!=nullptr && target!=nullptr) 
  {
   string s(source);
   string t(target);
  
  int S_len=s.length();
  int T_len=t.length();
  
  for(int i=0;i<=S_len;i++)
  {
      if(s.substr(i,T_len)==t)
      return i;
  }
  }
  
  return -1;
}

};
