/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 16-08-23 04:20
*/

class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // write your code here
        
        static Solution* instance;  
        
        return instance;  
    }
};