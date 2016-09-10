/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 16-08-31 01:55
*/

/*
II比I简单，一样的按层访问法。
由于是正方形矩阵，当n为奇数时，
最后只会剩下一个数字即matrix[n/2][n/2]，
最后不要忘记补填上这个数字。
*/
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
class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int>>ret(n,vector<int>(n,0));
        int nlvl = n/2; //The number of the circle:[min(n,n)+1]/2;
        int val =1;
        for(int i=0;i<nlvl;i++)
        {
            int last = n-1-i;
            for(int j=i;j<last;j++)
              ret[i][j] = val++;
            for(int j=i;j<last;j++)
              ret[j][last]=val++;
            for(int j=last;j>i;j--)
              ret[last][j] = val++;
            for(int j=last;j>i;j--)
              ret[j][i] = val++;
        }
        
        if( n%2 == 1) ret[n/2][n/2] = val;
        return ret;
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-spiral-matrix-i-ii.html