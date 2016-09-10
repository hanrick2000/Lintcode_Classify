/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/decode-ways
@Language: C++
@Datetime: 16-08-28 15:12
*/

/*
建立一位dp数组，长度比输入数组长多多2，全部初始化为1，
因为斐波那契数列的前两项也为1，然后从第三个数开始更新，对应数组的第一个数。
对每个数组首先判断其是否为0，若是将改为dp赋0，
若不是，赋上一个dp值，此时相当如加上了dp[i - 1],
然后看数组前一位是否存在，如果存在且满足前一位不是0，
且和当前为一起组成的两位数不大于26，则当前dp值加上dp[i - 2]
*/


class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if(s.empty()) return 0;
        int n=s.size();
        vector<int> dp(n+2,1);
        for(int i=2;i<n+2;i++)
        {
            if(s[i-2] == '0') dp[i]=0;
            else
              dp[i] = dp[i-1];
            if(i-3>=0 && (s[i-3] == '1'||(s[i-3] == '2' && s[i-2]<='6')))
            dp[i]+=dp[i-2];
        }
        return dp[n+1];
    }
};

//Good reference:http://www.cnblogs.com/grandyang/p/4313384.html