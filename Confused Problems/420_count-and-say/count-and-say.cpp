/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 16-08-26 00:27
*/

/*
逐个构建序列——根据第i-1个序列构建后第i个。
理解题目意思后便知道在扫描前一个序列ret时，需要一个计数变量count记录当前字符重复的次数，以及需要一个字符变量prev记录上一个字符的值。
当ret[i] = prev，则先不写入结果，而增加count。
当ret[i]!= prev，说明prev的重复结束，
需要将count和prev都写入结果，然后重置count为1，prev为ret[i]。
*/


class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if(n<1) return "";
        string ret = "1";
        
        for(int i=2;i<=n;i++)
        {
            string temp = "";
            int count = 1;
            char prev = ret[0];
            
            for(int j=1;j<ret.size();j++)
            {
                if(ret[j] == prev) count++;
                else
                {
                    temp += to_string(count);
                    temp.push_back(prev);
                    count = 1;
                    prev = ret[j];
                }
            }
            temp += to_string(count);
            temp.push_back(prev);
            ret = temp;
        }
        return ret;
    }
};

//Reference:http://bangbingsyb.blogspot.com/2014/11/leetcode-count-and-say.html