/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/super-ugly-number
@Language: C++
@Datetime: 16-07-11 00:17
*/

class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
       
      vector<int> res(1,1);
      int len=primes.size();
      vector<int>prime_array(len,0);
      vector<int>prime_array_res(len,1);
       
      int index=0;

       
      for(int i=1;i<n;i++)
      {
        //   prime_array[0]=res[primes[0]]*primes[0];
        //   prime_array[1]=res[primes[1]]*primes[1];
        //   ...
        //   prime_array[len-1]=res[primes[len-1]]*primes[len-1];
        
        while(index<len)
        {
            prime_array_res[index]=res[prime_array[index]]*primes[index];
            index++;
        }
        
        index=0;
        
        int mn=prime_array_res[0];
        index++;
        
        while(index<len)
        {
            mn=min(mn,prime_array_res[index]);
            index++;
        }
        
        index=0;
        
        while(index<len)
        {
            if(mn==prime_array_res[index]) prime_array[index]++;
            index++;
        }

        index=0;
        
        res.push_back(mn);
      }
       
        
      return res.back();
    }
};

// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {
//         vector<int> nums(n, 1);
//         int k = primes.size();
//         vector<int> index(k, 0);
        
//         for(int i=1; i<n; ++i){
//             int min_num = INT_MAX;
//             for(int j=0; j<k; ++j){
//                 min_num = min(min_num, nums[index[j]]*primes[j]);
//             }
//             nums[i] = min_num;
//             for(int j=0; j<k; ++j){
//                 if(min_num==nums[index[j]]*primes[j]) index[j]++;
//             }
//         }
//         return nums[n-1];
//     }
// };

// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {

//          vector<int> res(n,1);
//          int k=primes.size();
         
//          vector<int> index(k,0);
         
//          for(int i=1;i<n;i++)
//          {
//              int min_num=INT_MAX;
             
//              for(int j=0;j<k;j++)
//              {
//                  min_num=min(min_num,res[index[j]]*primes[j]);
//              }
             
//              res[i]=min_num;
             
//              for(int j=0;j<k;j++)
//              {
//                  if(min_num==res[index[j]]*primes[j]) index[j]++;
//              }
//          }
         
//          return res[n-1];
         
//     }
// };

