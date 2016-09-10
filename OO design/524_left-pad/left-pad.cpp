/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-08-31 21:41
*/

/*
如果给定的大小比原字符串的长度小的话，
返回原字符串，即不做任何处理，
如果大的话，再前面填充二者之差个给定的字符
*/
class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        //The defalut padChar is ' ';
        if (size <= originalStr.size()) return originalStr;
        return string(size - originalStr.size(), padChar) + originalStr;
    }
};

//http://www.cnblogs.com/grandyang/p/5434692.html