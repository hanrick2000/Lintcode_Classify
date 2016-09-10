/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/longest-consecutive-sequence
@Language: C++
@Datetime: 16-08-21 00:25
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        if(num.empty()) return 0; 
        unordered_set<int> ht;
        
        for(int i=0;i<num.size();i++)
        ht.insert(num[i]);
        
        int maxLen=1;
        for(int i=0;i<num.size();i++)
        {
            if(ht.empty()) break;
            int curLen = 0;
            int curNum = num[i];
            
            while(ht.count(curNum))
            {
                ht.erase(curNum);
                curLen++;
                curNum++;
            }
            
            curNum = num[i]-1;
            while(ht.count(curNum))
            {
                ht.erase(curNum);
                curLen++;
                curNum--;
            }
            
            maxLen = max(maxLen,curLen);
        }
        
        return maxLen;
    }
};




/*
既然要O(n)算法，排序显然不行，所以自然想到用hash table。将序列中的所有数存到一个unordered_set中。对于序列里任意一个数A[i]，我们可以通过set马上能知道A[i]+1和A[i]-1是否也在序列中。如果在，继续找A[i]+2和A[i]-2，以此类推，直到将整个连续序列找到。为了避免在扫描到A[i]-1时再次重复搜索该序列，在从每次搜索的同时将搜索到的数从set中删除。直到set中为空时，所有连续序列搜索结束。

复杂度：由于每个数字只被插入set一次，并删除一次，所以算法是O(n)的。
*/