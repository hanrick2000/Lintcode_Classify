/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-colors
@Language: C++
@Datetime: 16-08-21 16:23
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &A) {
        // write your code here
        int n=A.size();
        int left=0,right=n-1;
        int i=0;
        while(i<=right)
        {
            if(A[i]==0)
              swap(A[i++],A[left++]);
            else if(A[i]==1) 
              i++;
            else if(A[i]==2)
              swap(A[i],A[right--]);
        }
    }
};


// First method: two pointers;
// Another way : construct the colorful array;
/*
class Solution {
    public void sortColors(int[] nums) {
        int[] count = new int[3];
        for (int num: nums) {
            count[num]++;
        }
        int pos = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i] > 0) {
                nums[pos++] = i;
                count[i]--;
            }
        }
        return ;
    }
}
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-sort-colors.html

/*
思路：

这里要求one pass完成排序，需要利用只有数组元素只有3个数的特性，否则无法完成。排序完成后一定是0...01...12....2，所以可以扫描数组，当遇到0时，交换到前部，当遇到1时，交换到后部。用双指针left, right来记录当前已经就位的0序列和2序列的边界位置。

假设已经完成到如下所示的状态：

0......0   1......1  x1 x2 .... xm   2.....2
              |           |               |
            left        cur          right

(1) A[cur] = 1：已经就位，cur++即可
(2) A[cur] = 0：交换A[cur]和A[left]。由于A[left]=1或left=cur，所以交换以后A[cur]已经就位，cur++，left++
(3) A[cur] = 2：交换A[cur]和A[right]，right--。由于xm的值未知，cur不能增加，继续判断xm。
cur > right扫描结束。

*/