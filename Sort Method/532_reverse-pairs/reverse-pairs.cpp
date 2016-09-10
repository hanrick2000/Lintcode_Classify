/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reverse-pairs
@Language: C++
@Datetime: 16-08-28 16:55
*/

// -- Time complexity O(n^2) : cannot passed;
// class Solution {
// public:
//     /**
//      * @param A an array
//      * @return total of reverse pairs
//      */
//     long long reversePairs(vector<int>& A) {
//         // Write your code here
        
//         long long cnt=0;
        
//         for(int i=1;i<A.size();i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(A[j]>A[i]) cnt++;
//             }
//         }
        
//         return cnt;
//     }
// };

/*
思路是将给定数组从最后一个开始,用二分法插入到一个新的数组;
这样新数组就是有序的，那么此时该数字在新数组中的坐标就是
原数组中其右边所有较小数字的个数
*/

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        long long res = 0;
        vector<int> v;// Construct a new array;
        
        for(int i=A.size()-1;i>=0;i--)
        {
          int left=0,right=v.size();
          while(left<right)
          {
            int mid = (left + right)/2;
            if(A[i]>v[mid]) left = mid +1;      
            else
              right = mid;
          }
          v.insert(v.begin()+right,A[i]);
          res += right;
        }
        
        return res;
    }
};


//http://www.cnblogs.com/grandyang/p/5434414.html
//Count of Smaller Numbers After Self  -- Similiar problem;
//Good reference: http://www.cnblogs.com/grandyang/p/5078490.html

