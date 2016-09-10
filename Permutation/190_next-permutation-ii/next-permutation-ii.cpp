/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/next-permutation-ii
@Language: C++
@Datetime: 16-08-30 04:15
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &num) {
        // write your code here
        
        //Using the STL;
        //next_permutation(nums.begin(), nums.end());
        
        //Classic Method;
        
        if(num.size()<2) return;
        int n= num.size(),j = n-2;
        while(j>=0 && num[j]>=num[j+1]) j--;
        
        if(j<0)
        {
            sort(num.begin(),num.end());
            return;
        }
        
        int i=j+1;
        while(i<n && num[i]>num[j]) i++;
        i--;
        
        swap(num[i],num[j]);
        sort(num.begin()+j+1,num.end());
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-next-permutation.html
/*
思路：

遇到这类概念比较抽象的题目，写几个例子通常会帮助理解问题的规律：

7 2 5 2 3 1
7 2 5 3 1 2
7 2 5 3 2 1
7 3 1 2 2 5

其中红色的数字表示next permutation改变原数字的最高位。比如对于725321来说，由于5321由于从最低位到最高位是升序排列，已经达到该四位数字permutation的最大值。这时不得不改变第5位的2来增加数值。如何改变？为了使增量最小，在前4位中比第5位大的数(5, 3)中找一个最小的数，即数字3。用3替换2，而剩下5, 2, 2, 1四个数字要组成最低4位。由于第5位已经从2增加到3，同样为了使增量最小，我们希望剩下的4位数尽可能小。所以将他们从低到高位降序排列即可。总结上面的思考：

1. 从低位向高位（从右向左）找第一个递减的数：s[i]<s[i+1]。如果不存在，则表明该permutation已经最大，next permutation为当前序列的逆序。
2. 在s[i+1:n-1]中找一个j，使s[j]>s[i]>=s[j+1]，swap(s[i], s[j])
3. 将s[i+1:n-1]排序，从低位到高位单调递减。
*/