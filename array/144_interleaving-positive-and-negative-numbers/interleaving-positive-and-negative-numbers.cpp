/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/interleaving-positive-and-negative-numbers
@Language: C++
@Datetime: 16-08-29 17:08
*/

//O(1)
/*
先找出正数和负数哪个多，多的那个先开始
先设定好两个指针，一个代表正数的，一个代表负数的，
每次往前走2个 如果正数多，那么正数指针从0开始，负数指针从1开始
找到正数指针位置第一个为负的，负数指针位置第一个为正的，swap, 直到走到最后
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int negativeIdx = 0;
        int positiveIdx = 1;
        int positiveNum = 0;
        
        if(A.size()%2)// The problem already set the odd the default;
        {
            for(int i=0;i<A.size();i++)
            {
                if(A[i]>0) positiveNum++;
            }
            
            if(positiveNum > (A.size()/2))
            {
                positiveIdx = 0;
                negativeIdx = 1;
            }
        }
        
        while(negativeIdx < A.size() && positiveIdx < A.size())
        {
            while((negativeIdx < A.size()) && A[negativeIdx] < 0)
            negativeIdx += 2; 
            
            while ((positiveIdx < A.size()) && A[positiveIdx] > 0 )  
            positiveIdx += 2;  
            
            //正数指针位置第一个为负的，负数指针位置第一个为正的，swap;
            if (negativeIdx < A.size() && positiveIdx < A.size())  
            {  
             int tmp = A[negativeIdx];  
             A[negativeIdx] = A[positiveIdx];  
             A[positiveIdx] = tmp;  
            }  
        }
    }
};