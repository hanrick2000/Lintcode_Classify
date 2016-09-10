/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 16-08-30 04:53
*/

/*
   首先观察一个全排列， 例如：95412 = X

　　a.题目转换成按照字典序，这个全排列之前有多少个全排列。

　　b.X的前面的所有全排列中，对于位置1上可以是5, 4, 1, 2任意一个数，而且对应的全排列的基数都是4!个。

　　c.同理位置2, 3, 4, 5对应的基数分别是，3！，2！，1！，0！(0!==0)。

　　d.得到该位置对应的基数后，那么该位置对应多少个可变数字？9所在位置对应的可变数字的个数为4，分别是5,4,1,2；

　　　5所在位置对应的可变数字是4,1,2；4所在位置对应的可变数字是1,2,；1所在位置的对应的可变数字:无。2所在位置

　　   对应可变数也是无。

　　e.可以得到结论，X全排列某个位置上对应的可变数字的个数 == 这个数后面有多少个比它小的数的个数。

　　f.为了得到某个数后面有多少个比它小的数的个数，我们采用折半插入排序（从后向前插入）。
*/
/*
以4,1,2为例，4为第3大数,1为剩余序列第1大数，2为剩余序列第1大数，

故表达式为：(3-1)*2! + (1-1)*1! + (1-1)*0! + 1 = 5

以2,4,1为例，2为第2大数，4为剩余序列第2大数，1为剩余序列第1大数

故表达式为：(2-1)*2! + (2-1)*1! + (1-1)*0! + 1 = 4

这后面这个1一定要加，因为前面算的都是比该数小的数，加上这个1，才是该数是第几大数。
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        if (A.empty()) return 0;
        long long index = 1;
        long long factor = 1;//对应的基数:n!
        for (int i = A.size() - 1; i >= 0; i--) {
            int rank = 0;//可变数字的个数
            
            for (int j = i + 1; j < A.size(); j++) {
                if (A[i] > A[j]) 
                ++rank;//可变数字的个数
            }
            index += rank * factor;
            factor *= (A.size() - i);
        }
        return index;
    }
};

//http://www.cnblogs.com/hujunzheng/p/5020211.html
//http://massivealgorithms.blogspot.com/2016/04/lintcode-permutation-index.html
//http://www.tuwenzhai.com/d/94558250-815c-4b50-95f3-68d2ed883cd1/ab63e816-26ce-4339-bf94-dd4c325bb3ea