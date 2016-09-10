/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 16-06-24 02:58
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > res;

    void helper(int n,int k,int cur,vector<int> tmp){

        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }

        //当前层有可选的数从cur到n都有可能
        for(int i=cur;i<=n;i++){

            tmp.push_back(i);
            helper(n,k,i+1,tmp);//i+1
            tmp.pop_back();

        }

    }

    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<int> tmp;

        helper(n,k,1,tmp);

        return res;
    }
};