/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/delete-digits
@Language: C++
@Datetime: 16-08-22 18:56
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        // wirte your code here
        
        string s;
        
        if(k>A.size()) return s;
        int cnt =0;
        
        //Note: if nothing s="" means that everything has been deleted;
        for(int i=0;i<A.size();i++)
        {
            while(s.back()>A[i] && cnt<k && !s.empty())
            {
                s.pop_back();
                cnt++;
            }
            //如果前面有比它大的数字，那么就到把在它前面且比它大的数字都要删除掉，直到已经删掉k个数字。
            
            if(A[i]!='0'||!s.empty()) s.push_back(A[i]);
            //前置0要去掉
        }
        
        if(cnt<k) s.resize(s.size()-k+cnt);
        //如果遍历一遍发现删除的数字还不足k个，那么就把最后的k-cnt个删除掉
        return s;
    }
};


/*
可能一开始想到的是DFS暴力枚举，但是N大小为240显然暴力的方法并不可取。仔细想想发现其实还是很容易找到规律的，想让一个数字尽可能小，那么就要把小的数字尽量放到前面，如果前面有比它大的数字，那么就到把在它前面且比它大的数字都要删除掉，直到已经删掉k个数字。剩下的就是一些特殊情况与边界情况了，比如前置0要去掉，如果遍历一遍发现删除的数字还不足k个，那么就把最后的k-cnt个删除掉。下面是AC的代码。
*/

// This problem required to be not empty so that we could add the !s.empty();

