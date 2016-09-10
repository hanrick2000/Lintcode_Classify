/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 16-08-31 01:48
*/

// class Solution {
// public:
//     /**
//      * @param matrix a matrix of m x n elements
//      * @return an integer array
//      */
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         // Write your code here
//         vector<int> res;
//         if(matrix.empty()||matrix[0].empty()) return res;
//         int m=matrix.size(),n=matrix[0].size();
//         int c=m>n ? (n+1)/2 :(m+1)/2;//环数的计算公式是 min(m, n) / 2
//         int p=m,q=n;//p，q为当前环的高度和宽度
        
//         for(int i=0;i<c;i++,p-=2,q-=2)
//         {
//             for(int col=i;col<i+q;col++)
//               res.push_back(matrix[i][col]);
//             for(int row=i+1;row<i+p;row++)
//               res.push_back(matrix[row][i+q-1]);
//             if(p==1 || q==1) break;
//             for(int col=i+q-2;col>=i;col--)
//               res.push_back(matrix[i+p-1][col]);
//             for(int row=i+p-2;row>i;row--)
//               res.push_back(matrix[row][i]);
//         }
        
//         return res;
//     }
// };
/*
与Rotate Image那题类似，一层一层处理。
但这题有两个注意点：
1. m和n可以不同，
所以对于第i层来说，
最后一行为lastRow = m-1-i，
最后一列为lastCol = n-1-i。
所以层数由min(m,n)决定。
2. 当min(m,n)为奇数时，最后一层为一行或一列，需要特殊处理。
*/
class Solution{
public:    
    vector<int>spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int>ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        int m=matrix.size(),n=matrix[0].size();
        int nlv1 = (min(m,n)+1)/2;
        for(int i=0;i<nlv1;i++)
        {
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow == i)
            {
                for(int j=i;j<=lastCol;j++)
                {
                    ret.push_back(matrix[i][j]);
                }
            }
            else if(lastCol == i)
            {
                for(int j=i;j<=lastRow;j++)
                {
                    ret.push_back(matrix[j][i]);
                }
            }
            else
            {
                for(int j=i;j<lastCol;j++)
                  ret.push_back(matrix[i][j]);
                for(int j=i;j<lastRow;j++)
                  ret.push_back(matrix[j][lastCol]);
                for(int j=lastCol;j>i;j--)
                  ret.push_back(matrix[lastRow][j]);
                for(int j=lastRow;j>i;j--)
                  ret.push_back(matrix[j][i]);
            }
        }
        return ret;
    }
};

//Good reference: http://www.cnblogs.com/grandyang/p/4362675.html
//http://bangbingsyb.blogspot.com/2014/11/leetcode-spiral-matrix-i-ii.html