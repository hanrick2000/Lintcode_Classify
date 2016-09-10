/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-09-10 05:24
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
     
// Method one -- bubble sort;

    // void sortIntegers(vector<int>& A) {
    //     // Write your code here
    //     for(int i=0;i<A.size();i++)
    //     {
    //         for(int j=i+1;j<A.size();j++)
    //         {
    //             if(A[i]>A[j])
    //             swap(A[i],A[j]);
    //         }
    //     }
    // }
    
// Method two -- selection sort (move the smallest element to the front)

//   void sortIntegers(vector<int>& A)
//   {
//         for(int i=0;i<A.size();i++)
//         {
//             int min_idx = i;
//             for(int j=i+1;j<A.size();j++)
//             {
//                 if(A[j]<A[min_idx])
//                 min_idx = j;
//             }
//             swap(A[i],A[min_idx]);
//         }
//   }
   
// Method three -- insertion sort

void sortIntegers(vector<int>& A) {
        for (int n = 0; n < A.size(); ++n) {
            for (int i = n - 1; i >= 0 && A[i] > A[i + 1]; i--) {
                swap(A[i], A[i + 1]);
            }
        }
    }

   
   
};