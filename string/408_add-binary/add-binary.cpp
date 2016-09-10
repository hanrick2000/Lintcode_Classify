/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-08-25 19:44
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        if(a == "0") return b;
        if(b == "0") return a;
        
        string res;
        int carry = 0;
        int ai,bj,sum;
        char val;
        
        for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--)
        {
            ai = i>=0 ? a[i]-'0':0;
            bj = j>=0 ? b[j]-'0':0;
            
            sum = ai + bj +carry;
            val = sum%2 ?'1':'0';
            carry = sum/2;
            res.insert(res.begin(),val);// Insert in the front 
        }
        
        if(carry == 1) res.insert(res.begin(),'1');
        
        return res;
    }
};