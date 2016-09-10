/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 16-09-06 23:54
*/


//-- My own solution : cannot be passed;

// class Solution {
// public:
//     /*
//      * param k : As description.
//      * param n : As description.
//      * return: How many k's between 0 and n.
//      */
//     int digitCounts(int k, int n) {
//         // write your code here
        
//         /*
        
//         k!=0;
        
//         n=10  : k; 1;
//         n=100 : k,1k,2k,3k,...,k0,..,k9,...,9k;10*1+10-1 = 9*(1)+10;
//         n=1000: k,1k,2k,3k,...,k0,..,k9,...,9k;
//                 10k,11k,12k,13k,...,1k0,..,1k9,...,19k;
//                 20k,21k,22k,23k,...,2k0,..,2k9,...,29k;
//                 ...
//                 k00,...,k99;
//                 ...
//                 90k,91k,92k,93k,...,9k0,..,9k9,...,99k;
                
//                 // 10*(10*1+10*1-1)+100-(10*1+10*1-1) = 9*(9*(1))+10*10
//         n=10000:9*(9*(9*(1)))+10*10*10    
//         ...
        
//         k = 0;
        
//         n=10 : 1;
//         n=100 : 10*1;
//         n=1000:10*10*1
        
//         */
        
//         if(k==0) return n/10+1;
//         if(n<0)  return 0;
//         if(n<10 && n>=0) return 1;
        
//         int Nine_Part=1,Ten_Part=1;
        
//         while(n/10)
//         {
//             Nine_Part *= 9;
//             Ten_Part  *= 10;
//             n/=10;
//         }
//         return Nine_Part+Ten_Part;
//     }
// };

//--Calculate each bits(decemical): Time:O(N) Space:O(1)
//From 0-9; 10-19; 20-29;...
class Solution{
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        if(k==0) return n/10+1;
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            int num = i;// Observe each number for one time;
            while (num > 0) {
                //Each bit in each level, for 1109--9; 110--0;11--1;1--1; 
                if (num % 10 == k) 
                {
                    cnt++;
                }
                num /= 10;// Next higher level bit, for 1109, then 110, then 11
            }
        }
        return cnt;
    }
};

// Turn into the string--Time:O(N^2) Space:O(1)
// class Solution {
// public:
//     /*
//      * param k : As description.
//      * param n : As description.
//      * return: How many k's between 0 and n.
//      */
//     int digitCounts(int k, int n) {
//         char c = k + '0';
//         int count = 0;
//         for (int i = k; i <= n; i++) {
//             for (auto s : to_string(i)) {
//                 if (s == c) count++;
//             }
//         }
//         return count;
//     }
// };
