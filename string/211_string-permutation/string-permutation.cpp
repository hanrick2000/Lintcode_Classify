/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/string-permutation
@Language: C++
@Datetime: 16-09-06 06:59
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        
        if(A.length() != B.length()) return false;
        
        unordered_map<char,int> ht;
        
        for(int i=0;i<A.size();i++)
        {
            ht[A[i]]++;
        }
        
        for(int i=0;i<B.size();i++)
        {
            ht[B[i]]--;
            if(ht[B[i]]< 0 )
            return  false;
        }
        
        return true;
    }
};