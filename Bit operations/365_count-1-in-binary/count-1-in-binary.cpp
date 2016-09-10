/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: C++
@Datetime: 16-08-24 09:16
*/

/*
每次“&”都会去掉num最右边的1.
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。
举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here
     
        int sum=0;
        
        while (num)
        {
            sum++;
            num = num & (num-1);
        }
        
        return sum;
    }
};

/*
第一种：

原数除以2后，数字将减少一个0

若余数是1则，减少一个1，记录1的个数

若余数是0则，减少一个0，记录0的个数

第二种：

利用位运算

0&1 =0

1&1 =1

这个32位数与0000 0001 与运算的值是1，记录1的个数

即：count += num & 0x01

num右移一位

num=num>>1

*/

//Good reference: https://segmentfault.com/a/1190000004499921
//http://www.cnblogs.com/CheeseZH/p/4999835.html