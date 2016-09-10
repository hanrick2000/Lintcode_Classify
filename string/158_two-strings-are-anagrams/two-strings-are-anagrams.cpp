/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-08-21 16:46
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string A, string B) {
        // write your code here
        
        if(A.length()!=B.length()) return false; 
        //First of all, A and B will have the same length;
        
        unordered_map<char, int> h;
        
        for (const auto& c: A) {
            ++h[c];//To calculate  the frequency of each character in A
        }

        for (const auto& c: B) {
            if (--h[c] < 0)//If the frequency of each character in B is not the same with the A, just say B is not anagram of A;
            {
                return false;
            }
        }

        return true;
    
    }
};