/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-08-21 16:46
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    // bool compareStrings(string A, string B) {
    //     // write your code here
        
        
    // }
    
    // bool compareStrings(string A, string B) {
    //     if (A.size() < B.size()) {
    //         return false;
    //     }

    //     const int AlphabetNum = 26;
    //     int letterCount[AlphabetNum] = {0};
    //     for (int i = 0; i != A.size(); ++i) {
    //         ++letterCount[A[i] - 'A'];
    //     }
    //     for (int i = 0; i != B.size(); ++i) {
    //         --letterCount[B[i] - 'A'];
    //         if (letterCount[B[i] - 'A'] < 0) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }
    
    bool compareStrings(string A, string B) {
        
        unordered_map<char, int> h;
        
        for (const auto& c: A) {
            ++h[c];//To calculate  the frequency of each character in A
        }

        for (const auto& c: B) {
            if (--h[c] < 0)//If the frequency of each character in B is not the same with the A, just say B is not part of A;
            {
                return false;
            }
        }

        return true;
    }
};
