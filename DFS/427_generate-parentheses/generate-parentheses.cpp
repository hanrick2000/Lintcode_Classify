/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: C++
@Datetime: 16-08-26 06:18
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> allComb;
        string comb;
        findParenthesis(n,0,0,comb,allComb);
        return allComb;
    }
    
    void findParenthesis(int n,int nleft,int nright,string& comb,vector<string>& allComb)
    {
        if(n==nleft && n==nright)
        {
            allComb.push_back(comb);
            return;
        }
        
        if(nleft<n)
        {
            comb.push_back('(');
            findParenthesis(n,nleft+1,nright,comb,allComb);
            comb.pop_back();
        }
        
        if(nright<nleft)
        {
            comb.push_back(')');
            findParenthesis(n,nleft,nright+1,comb,allComb);
            comb.pop_back();
        }
    }
};


/*
1. 只要"("的数量没有超过n，都可以插入"("。
2. 而可以插入")"的前提则是当前的"("数量必须要多余当前的")"数量。
*/