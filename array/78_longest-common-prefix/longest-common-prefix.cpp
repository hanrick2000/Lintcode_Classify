/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 16-06-22 02:14
*/

// class Solution {
// public:    
//     /**
//      * @param strs: A list of strings
//      * @return: The longest common prefix
//      */
//     string longestCommonPrefix(vector<string> &strs) {
//         // write your code here
        
//         string res="";
        
//         int row=strs.size();
//         int col=strs[0].size();
//         int c=0;
//         int r=1;
//         int end_flag=0;
        

        
//         while(r<row && c<col)
//         {
//           if(strs[r][c]!=strs[r-1][c]) 
//           {
//           end_flag=1;
//           break;
//           }
           
          
//           if(end_flag) break;
//           else
//           {
//           res.push_back(strs[0][c]);
//           c++;
//           }
//         }
        
//         return res;
//     }
// };


// Time:  O(n * k), k is the length of the common prefix
// Space: O(1)

// // BFS
// class Solution {
// public:
//     /**
//      * @param strs: A list of strings
//      * @return: The longest common prefix
//      */
//     string longestCommonPrefix(vector<string> &strs) {
//         if (strs.empty()) {
//             return "";
//         }

//         for (int i = 0; i < strs[0].length(); ++i) {
//             for (const auto& str : strs) {
//                 if (i >= str.length() || str[i] != strs[0][i]) {
//                     return strs[0].substr(0, i);
//                 }
//             }
//         }
//         return strs[0];
//     }
// };

// Time:  O(n * l), l is the max length of strings
// Space: O(1)

// DFS
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
          
        for (int i = 0; i < strs[0].length(); i++) {
              for (int j = 1; j < strs.size(); j++)
                  if (strs[j].length() == i || strs[j][i] != strs[0][i])
                      return strs[0].substr(0, i);
        }
        
        return strs[0];
     }
};