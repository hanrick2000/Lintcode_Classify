/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 16-07-11 01:28
*/

// class Solution {
// public:
//     /**
//      * @param A and B: sorted integer array A and B.
//      * @return: A new sorted integer array
//      */
//     vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
//         // write your code here
//         if (A.empty()) {
//             return B;
//         }
//         if (B.empty()) {
//             return A;
//         }

//         int sizeA = A.size();
//         int sizeB = B.size();
//         int sizeC = sizeA + sizeB;
//         vector<int>C(sizeC);

//         while (sizeA > 0 && sizeB > 0) {
//             if (A[sizeA - 1] > B[sizeB - 1]) {
//                 C[--sizeC] = A[--sizeA];
//             } else {
//                 C[--sizeC] = B[--sizeB];
//             }
//         }
//         while (sizeA > 0) {
//             C[--sizeC] = A[--sizeA];
//         }
//         while (sizeB > 0) {
//             C[--sizeC] = B[--sizeB];
//         }

//         return C;
//     }
// };

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here

     if(A.empty()) return B;
     if(B.empty()) return A;
     
     int len_a=A.size();
     int len_b=B.size();
     int len_c=A.size()+B.size();
     vector<int>C(len_c);
     len_a--;
     len_b--;
     len_c--;
     
     while(len_a>=0 && len_b>=0)
     {
         
         if(A[len_a]>B[len_b]) C[len_c--]=A[len_a--];
         else C[len_c--]=B[len_b--];
     }
     
     while(len_a>=0) C[len_c--]=A[len_a--];
     while(len_b>=0) C[len_c--]=B[len_b--];
    
     return C;
    }
};