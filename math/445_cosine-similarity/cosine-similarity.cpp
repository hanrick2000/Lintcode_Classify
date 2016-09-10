/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: C++
@Datetime: 16-08-26 05:58
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        
        if(A.empty() || B.empty()) return 2.0000;
        
        double sum1=0,sum2=0,sum3=0;
        
        for(int i=0;i<A.size();i++)
        {
            sum1+=A[i]*B[i];
            sum2+=A[i]*A[i];
            sum3+=B[i]*B[i];
        }
        
        if (0 == sum1 && 0 == sum2 && 0 == sum3) 
        return 2;

        double res = 0.0;
        
        res  = sum1 / (sqrt(sum2) * sqrt(sum3));
        
        return res;
    }
};
