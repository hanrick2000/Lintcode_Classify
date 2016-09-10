/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/gray-code
@Language: C++
@Datetime: 16-08-25 20:00
*/

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        
        for (int i = 0; i < pow(2, n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        
        return res;
    }
};


//Good reference: http://www.cnblogs.com/grandyang/p/5787682.html
//http://www.cnblogs.com/grandyang/p/4315649.html
//http://www.cnblogs.com/grandyang/p/4315607.html