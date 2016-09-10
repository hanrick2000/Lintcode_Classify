/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: C++
@Datetime: 16-08-29 18:18
*/

/*
III是这三题中最难的。允许两次买卖，但同一时间只允许持有一支股票。
也就意味着这两次买卖在时间跨度上不能有重叠
（当然第一次的卖出时间和第二次的买入时间可以是同一天)。
既然不能有重叠可以将整个序列以任意坐标i为分割点，分割成两部分：
prices[0:n-1] => prices[0:i] + prices[i:n-1]
对于这个特定分割来说，最大收益为两段的最大收益之和。
每一段的最大收益当然可以用I的解法来做。
而III的解一定是对所有0<=i<=n-1的分割的最大收益中取一个最大值。
为了增加计算效率，考虑采用dp来做bookkeeping。目标是对每个坐标i：
1. 计算A[0:i]的收益最大值：用minPrice记录i左边的最低价格，用maxLeftProfit记录左侧最大收益
2. 计算A[i:n-1]的收益最大值：用maxPrices记录i右边的最高价格，用maxRightProfit记录右侧最大收益。
3. 最后这两个收益之和便是以i为分割的最大收益。将序列从左向右扫一遍可以获取1，从右向左扫一遍可以获取2。相加后取最大值即为答案。
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty()) return 0;
        int n=prices.size();
        vector<int>leftProfit(n,0);
        
        //计算A[0:i]的收益最大值
        int maxLeftProfit=0,minPrice = prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<minPrice)
              minPrice = prices[i];
            else
              maxLeftProfit = max(maxLeftProfit,prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;  
        }
        
        //计算A[i:n-1]的收益最大值
        //最后这两个收益之和便是以i为分割的最大收益
        int ret = leftProfit[n-1];
        int maxRightProfit = 0,maxPrice = prices[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]>maxPrice)
              maxPrice = prices[i];
            else 
              maxRightProfit = max(maxRightProfit,maxPrice-prices[i]);
        //（当然第一次的卖出时间和第二次的买入时间可以是同一天)。
            ret = max(ret,maxRightProfit+leftProfit[i]); 
        // Calculate the same day for selling 
        }
        
        return ret;
    }
};