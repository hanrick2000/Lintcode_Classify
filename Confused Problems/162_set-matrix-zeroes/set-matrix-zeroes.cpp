/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/set-matrix-zeroes
@Language: C++
@Datetime: 16-08-22 00:22
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        
        // find if the 1st row/col needs to be set as zero
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        for(int j=0; j<n; j++) {
            if(matrix[0][j]==0) {
                isFirstRowZero = true;
                break;
            }
        }
        for(int i=0; i<m; i++) {
            if(matrix[i][0]==0) {
                isFirstColZero = true;
                break;
            }
        }
        
        // use 1st row/col to record whether to set each col/row as zero
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // set rows & cols
        for(int i=1; i<m; i++) {
            if(matrix[i][0]==0) setRowCol(matrix, i, true);
        }
        for(int j=1; j<n; j++) {
            if(matrix[0][j]==0) setRowCol(matrix, j, false);
        }
        
        // set first row & col
        if(isFirstRowZero) setRowCol(matrix, 0, true);
        if(isFirstColZero) setRowCol(matrix, 0, false);
    }
    
    void setRowCol(vector<vector<int>> &matrix, int index, bool isSetRow) {
        if(matrix.empty() || matrix[0].empty() || index<0) return;
        int m = matrix.size(), n = matrix[0].size();
        if((isSetRow && index>=m) || (!isSetRow && index>=n)) return;
        
        if(isSetRow) {
            for(int j=0; j<n; j++)
                matrix[index][j] = 0;
        }
        else {
            for(int i=0; i<m; i++)
                matrix[i][index] = 0;
        }
    }
};

// O(1) solution

/*
1. O(mn)解法：克隆原来的matrix，然后扫描原来的matrix，遇到0，则在克隆版本中将对应的行列置0。
2. O(m+n)解法：用两个bool数组O(n)和O(m)，分别记录每行和每列的是否需要被置0。最后根据这两个数组来置0整个矩阵。
3. O(1)解法：用第0行和第0列来记录第1 ~ m-1行和第1 ~ n-1列是否需要置0。而用两个变量记录第0行和第0列是否需要置0。
*/

