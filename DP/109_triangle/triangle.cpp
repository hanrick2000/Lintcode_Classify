/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 16-08-18 21:11
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            
            triangle[i][j]+=min(triangle[i+1][j+1],triangle[i+1][j]);
        }
         
         return triangle[0][0];
    }
};
