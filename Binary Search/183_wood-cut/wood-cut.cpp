/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/wood-cut
@Language: C++
@Datetime: 16-08-23 00:52
*/

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        
        int lb=0,ub=0;
        
        for(auto l:L)
        {
            if(l+1>ub)
            ub=l+1;
        }
        
        while(lb+1<ub)
        {
            int mid=lb+(ub-lb)/2;
            if(C(L,k,mid)) lb=mid;
            else ub=mid;
        }
        
        return lb;
    }
    
    int C(vector<int>L, int k,int mid)
    {
        int sum=0;
        for(auto l:L)
        {
            sum += l/mid;
        }
        
        return sum>=k;
    }
};

