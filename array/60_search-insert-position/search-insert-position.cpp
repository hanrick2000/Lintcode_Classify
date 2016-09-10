/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-06-20 17:37
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        
        if(A.empty()) return 0;
        
        int bgn=0;
        int end=A.size()-1,mid;
        
        while(bgn<=end)
        {
            mid=(bgn+end)/2;
            if(A[mid]==target) return mid;
            else if(A[mid]<target)bgn=mid+1;
            else end=mid-1;
        }
        if(target>A[mid])
        return mid+1;
        else
        return mid;
    }
};