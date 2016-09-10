/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 16-07-11 02:01
*/

// class Solution {
// public:
//     /**
//      * @param str: a string
//      * @param offset: an integer
//      * @return: nothing
//      */
//     // void rotateString(string &str,int offset){
//     //     //wirte your code here
//     //     if(str.empty()) return;
        
//     //     string ret;
//     //     int len=str.size();
//     //     offset %= len;
        
//     //     if(offset>=len) return ;
        
//     //     else
//     //     {
//     //     ret.append(str.substr((len-offset),offset));
//     //     ret.append(str.substr(0,(len-offset)));
//     //     str=ret;
        
//     //     return ;
//     //     }
        
//     // }
    
//     void rotateString(string &A, int offset) {
//         if (!A.empty()) {
            
//             offset %= A.length();//This is beacuse the offset  given this way
            
//             reverse(A.begin(), A.begin() + A.length() - offset);
//             reverse(A.begin() + A.length() - offset, A.end());
//             reverse(A.begin(), A.end());
//         }
     
//     return ;
//     }
// };


class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    
    void rotateString(string &A, int offset) {

     if(!A.empty()) 
     {
        offset %= A.length();
        reverse(A.begin(),A.end()-offset);
        reverse(A.end()-offset,A.end());
        reverse(A.begin(),A.end());
     }
     
    }
};
