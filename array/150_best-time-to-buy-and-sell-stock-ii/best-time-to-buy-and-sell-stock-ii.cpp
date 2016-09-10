/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-ii
@Language: C++
@Datetime: 16-08-29 17:53
*/

/*
I并没有限制总的买卖次数，只限制了当天只能买或卖。
所以可以采用greedy的方法，来获得所有可能的正利润。
以如下序列说明：
2 1 3 4 5 4 2 8 7 
只要prices[i]-prices[i-1]>0，
我们就在第i-1天买入，第i天抛出。
这样可以包括所有可能赚取利润的区间。
*/

//Note:you can buy the stock many times per day;
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int ret=0;
        for(int i=1;i<prices.size();i++)
        {
            ret+=prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        }
        return ret;
    }
};