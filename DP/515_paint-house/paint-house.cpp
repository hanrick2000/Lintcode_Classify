/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/paint-house
@Language: C++
@Datetime: 16-08-28 16:08
*/

class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        if(costs.empty()) return 0;
        int n = costs.size(), r=0,g=0,b=0;
        
        for(int i=0;i<n;i++)
        {
            int rr=r,bb=b,gg=g;
            r=costs[i][0] + min(bb,gg);
            b=costs[i][1] + min(rr,gg);
            g=costs[i][2] + min(rr,bb);
        }
      return min(r,min(b,g));   
    }
};


//http://www.cnblogs.com/jcliBlogger/p/4729957.html