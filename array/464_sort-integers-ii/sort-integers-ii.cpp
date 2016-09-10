/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: C++
@Datetime: 16-09-10 06:06
*/

// class Solution {
// public:
//     /**
//      * @param A an integer array
//      * @return void
//      */

// // Method one -- QuickSort;
// // Time:  O(nlogn)
// // Space: O(logn)     
     
// void QuickSort(vector<int>& A, int start ,int end)
//      {
//          int l=start, r=end, mid=A[(l+r)/2];
         
//          while(l<=r)
//          {
//              while(l<=r && A[r]>mid) r--;
//              while(l<=r && A[l]<mid) l++;
//              if(l<=r)
//              {
//                  swap(A[r],A[l]);
//                  r--;
//                  l++;
//              }
//          }
    
//          if(start<r)
//          QuickSort(A,start,r);
         
//          if(l<end)
//          QuickSort(A,l,end);
         
//      }
     
// void sortIntegers2(vector<int>& A) {
//         // Write your code here
//         if(A.empty()) return;
//         QuickSort(A,0,A.size()-1);
//     }
    
// };


// Time:  O(nlogn)
// Space: O(n)
//http://quiz.geeksforgeeks.org/merge-sort/
// Merge sort. (stable)--Divide and Conquer 
// class Solution {
// public:
//     /**
//      * @param A an integer array
//      * @return void
//      */
//     void sortIntegers2(vector<int>& A) {
//         mergeSort(A, 0, A.size() - 1);
//     }

// private:

// /* l is for left index and r is right index of the
//   sub-array of arr to be sorted */
// void mergeSort(vector<int>& arr, int l, int r)
// {
//     if (l < r)
//     {
//         // Same as (l+r)/2, but avoids overflow for
//         // large l and h
//         int m = (r+l)/2;
 
//         // Sort first and second halves
//         mergeSort(arr, l, m);
//         mergeSort(arr, m+1, r);
 
//         merge(arr, l, m, r);
//     }
    
//     return;
// }
    
// void merge(vector<int>& arr, int l, int m, int r)
// {
//     int i, j, k;
//     int n1 = m - l + 1; // l ~ m;
//     int n2 =  r - m; // m+1 ~ r;
 
//     /* create temp arrays */
//     int L[n1], R[n2];
 
//     /* Copy data to temp arrays L[] and R[] */
//     for (i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for (j = 0; j < n2; j++)
//         R[j] = arr[m + 1+ j];
 
//     //Treat the following as the sort array and merge into an new array;
    
//     /* Merge the temp arrays back into arr[l..r]*/
//     i = 0; // Initial index of first subarray
//     j = 0; // Initial index of second subarray
//     k = l; // Initial index of merged subarray
//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j])
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
 
//     /* Copy the remaining elements of L[], if there
//       are any */
//     while (i < n1)
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     /* Copy the remaining elements of R[], if there
//       are any */
//     while (j < n2)
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
// };

// Time:  O(nlogn)
// Space: O(1)
// Heap sort. (unstable)
// http://quiz.geeksforgeeks.org/heap-sort/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
     
void sortIntegers2(vector<int>& A) {
        heapSort(A,A.size());
    }


// main function to do heap sort
void heapSort(vector<int>& arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

};

