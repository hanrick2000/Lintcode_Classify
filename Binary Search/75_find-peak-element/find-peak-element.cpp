/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/find-peak-element
@Language: C++
@Datetime: 16-06-21 19:45
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        
        if (A.size() == 0) return -1;

        int l = 0, r = A.size() - 1;
        
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            // peak in the 0 -> mid-1;
            if (A[mid] < A[mid - 1]) {
                r = mid-1;
            }
            // peak in the mid+1 -> l;
            else if (A[mid] < A[mid + 1]) {
                l = mid+1;
            } else {
                return mid;
            }
        }

        int mid = A[l] > A[r] ? l : r;
        return mid;
        
    }
};


