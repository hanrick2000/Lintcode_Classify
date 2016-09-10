/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/n-queens-ii
@Language: C++
@Datetime: 16-08-12 23:57
*/

// class Solution {
// public:
//     /**
//      * Calculate the total number of distinct N-Queen solutions.
//      * @param n: The number of queens.
//      * @return: The total number of distinct solutions.
//      */
//     int totalNQueens(int n) {
//         // write your code here
        
        
//     }
// };

//Online:http://bangbingsyb.blogspot.com/2014/11/leetcode-n-queens-i-ii.html

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col;//used for the cols comparation
        int totSol = 0;
        solveNQ(n, 0, col, totSol);
        return totSol;
    }
    
    void solveNQ(int n, int irow, vector<int> &col, int &totSol) {
        if(irow==n) {
            totSol++;
            return;
        }
        
        for(int icol=0; icol<n; icol++) {
            if(validPos(col, irow, icol)) {
                col.push_back(icol);
                solveNQ(n, irow+1, col, totSol);
                col.pop_back();
            }
        }
    }
    
    bool validPos(vector<int> &col, int irow, int icol) {
        if(irow<col.size()) return false;
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
                return false;
        }
        return true;
    }    
};
