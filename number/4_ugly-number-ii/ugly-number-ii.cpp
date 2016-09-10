/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 16-09-06 23:59
*/

// class Solution {
// public:
//     /*
//      * @param n an integer
//      * @return the nth prime number as description.
//      */
    
//     int nthUglyNumber(int n) 
//     {
//         vector<int> res(1, 1);
        
//         int i2 = 0, i3 = 0, i5 = 0;
        
//         while (res.size() < n) {
            
//             int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
//             int mn = min(m2, min(m3, m5));
            
//             if (mn == m2) ++i2;
//             if (mn == m3) ++i3;
//             if (mn == m5) ++i5;
            
//             res.push_back(mn);
//         }
        
//         // return res[n-1];
//         return res.back(); //Find the last element
//     }
    
    
// };

/*
这道题是之前那道Ugly Number 丑陋数的延伸，这里让我们找到第n个丑陋数，还好题目中给了很多提示，基本上相当于告诉我们解法了，根据提示中的信息，我们知道丑陋数序列可以拆分为下面3个子列表：

(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …

仔细观察上述三个列表，我们可以发现每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列
*/

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    
    int nthUglyNumber(int n) 
    {
        
        vector<int> res(1,1);
        
        int i2=0,i3=0,i5=0;
        
        for(int i=1;i<n;i++)
        {
            int m2=res[i2]*2;//the last 2's result times 2 
            int m3=res[i3]*3;//the last 3's result times 3
            int m5=res[i5]*5;//the last 5's result times 5
            int mn=min(m2,min(m3,m5));//Gain the min result of the three
            
            if(m2==mn) i2++;//if min equals the 2's results, 2's increased
            if(m3==mn) i3++;//if min equals the 3's results, 3's increased
            if(m5==mn) i5++;//if min equals the 5's results, 5's increased
            
            res.push_back(mn);//push the current ugly number into the result.
        }

          return res.back();//Find the nth ugly number
    }
    
    
};