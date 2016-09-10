/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/rotate-image
@Language: C++
@Datetime: 16-08-22 00:08
*/

// class Solution {
// public:
//     /**
//      * @param matrix: A list of lists of integers
//      * @return: Void
//      */
//     void rotate(vector<vector<int>> &matrix) {
//         // write your code here
//         int start=0,end=matrix.size()-1;
//         while(start<end)
//         {
//             for(int i=start;i<end;i++)
//             {
//                 int offset=i-start;
//                 int temp=matrix[start][i];
//                 matrix[start][i]=matrix[end-offset][start];
//                 matrix[end-offset][start]=matrix[end][end-offset];
//                 matrix[end][end-offset]=matrix[start+offset][end];
//                 matrix[start+offset][end]=temp;
//             }
            
//             start++;
//             end--;
//         }
        
        
//     }
// };

// class Solution{
// public:
//     /**
//      * @param matrix: A list of lists of integers
//      * @return: Void
//      */
//     void rotate(vector<vector<int>> &matrix) {
//         const int n = matrix.size();
//         // Anti-diagonal mirror.
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n - i; ++j) {
//                 swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
//             }
//         }
//         // Horizontal mirror.
//         for (int i = 0; i < n / 2; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 swap(matrix[i][j], matrix[n - 1 - i][j]);
//             }
//         }
//     }
// };

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int>> &matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1- j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};