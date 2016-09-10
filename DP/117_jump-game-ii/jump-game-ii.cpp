/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/jump-game-ii
@Language: C++
@Datetime: 16-08-18 23:01
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // write your code here
        
        int n=A.size();
        
        int res=0,i=0,cur=0;
        
        while(cur<n-1)//0 ~ (n-1)
        {
        int pre=cur;//the initial condition
        while(i<=pre)//While the postion i is less than the steps distance;
        //We need to update the maxium position we could reach;
        {
            cur=max(cur,i+A[i]);
            i++;
        }
        res++;//after the while loops means we need to jump;
        }
        
        return res;
    }
};
/*
我们需要两个变量cur和pre分别来保存当前的能到达的最远位置和之前能到达的最远位置，只要cur未达到最后一个位置则循环继续，pre记录cur的值，如果当前位置i小于等于pre，则更新cur然后i自增1。更新cur的方法是比较当前的cur和i + A[i]之中的较大值，等i循环到pre的值时，跳跃的步数加一，如果题目中未说明是否能到达末尾，我们还可以判断此时pre和cur是否相等，如果相等说明cur没有更新，即无法到达末尾位置，返回-1
*/