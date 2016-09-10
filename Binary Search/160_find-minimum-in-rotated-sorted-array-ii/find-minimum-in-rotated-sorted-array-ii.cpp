/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-06-21 19:25
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if (num.empty()) {
            return -1;
        }

        vector<int>::size_type start = 0;
        vector<int>::size_type end = num.size() - 1;
        vector<int>::size_type mid;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            // start -> mid : sorted; min is in the mid -> end; start=mid;
            if (num[mid] > num[end]) {
                start = mid;
            } // mid -> end : sorted; min is in the start -> mid; end=mid;
            else if (num[mid] < num[end]) {
                end = mid;
            }else{
                --end;
            }
        }

        if (num[start] < num[end]) {
            return num[start];
        } else {
            return num[end];
        }
    }
};