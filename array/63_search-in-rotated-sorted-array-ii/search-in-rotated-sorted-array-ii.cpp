/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/search-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-06-21 19:10
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        
        if (A.empty()) {
            return false;
        }

        int start = 0;
        int end = A.size() - 1;
        int mid;

        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (target == A[mid]) {
                return true;
            }
            if (A[start] < A[mid]) {
                // situation 1, numbers between start and mid are sorted
                if (A[start] <= target && target < A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if (A[start] > A[mid]) {
                // situation 2, numbers between mid and end are sorted
                if (A[mid] < target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else  {
                // increment start
                ++start;
            }
        }

        if (A[start] == target || A[end] == target) {
            return true;
        }
        return false;
    }
};

/*  
    前一题我们利用A[start] < A[mid]这一关键信息，而在此题中由于有重复元素的存在，
    在A[start] == A[mid]时无法确定有序数组，此时只能依次递增start/递减end以缩小搜索范围，
    时间复杂度最差变为O(n)。
*/