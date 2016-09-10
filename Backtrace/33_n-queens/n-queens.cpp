/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/n-queens
@Language: C++
@Datetime: 16-08-12 23:57
*/

// class Solution {
// public:
//     /**
//      * Get all distinct N-Queen solutions
//      * @param n: The number of queens
//      * @return: All distinct solutions
//      * For example, A string '...Q' shows a queen on forth position
//      */
    
//     //Method one: for the purpose of my own solution
    
//     // vector<vector<string>> solveNQueens(int n) {
//     //     // write your code here
        
//     //     vector<vector<string>> res;
//     //     vector<string> MyStr;
//     //     string s="....";
//     //     vector<vector<int>>flag(true);
        
//     //     for(int i=0;i<n;i++)
//     //     {
//     //      s[i]='Q';
//     //      //Marking the diagonal，the row and the column as the flase;
//     //      //When dectecting the flase, place the Q on the next col and do the cycle;
//     //      //if there is one row, can't place the Q: continue;
//     //      //when all the rows can place the Q: push the Mystr into the res
//     //     }
        
//     // }
    
// //Method two : online resources
// //http://bangbingsyb.blogspot.com/2014/11/leetcode-n-queens-i-ii.html
// /*
// 1. 逐行放置皇后：排除在同一行的可能。
// 2. 记录之前所放皇后的列坐标：col[i]=j表示第i行的皇后在第j列。这样在放置第i+1行时，只要保证col[i+1] != col[k], k=0...i 即可。
// 3. 对角线判断：对于任意(i1, col[i1])和(i2, col[i2])，只有当abs(i1-i2) = abs(col[i1]-col[i2])时，两皇后才在同一对角线。
// */

// };

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> allSol;
        vector<string> sol;//Used for setting the string;
        vector<int> col;//Used for the columns comparation;
        solveNQ(n, 0, col, sol, allSol);
        return allSol;
    }
    
    void solveNQ(int n, int irow, vector<int> &col, vector<string> &sol, vector<vector<string>> &allSol) {
        if(irow==n) {
            allSol.push_back(sol);
            return;
        }
        
        for(int icol=0; icol<n; icol++) {
            if(validPos(col, irow, icol)) {
                string s(n,'.');//Class constructor;
                s[icol] = 'Q';
                sol.push_back(s);
                col.push_back(icol);
                solveNQ(n, irow+1, col, sol, allSol);
                sol.pop_back();
                col.pop_back();
            }
        }
    }
    
    bool validPos(vector<int> &col, int irow, int icol) {
        //if(irow<col.size()) return false;
        for(int i=0; i<col.size(); i++) {
            if(icol==col[i] || abs(irow-i)==abs(icol-col[i]))
                return false;
        }
        return true;
    }
};