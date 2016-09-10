/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-07-12 02:34
*/

// class Solution {
// public:
//     /**
//      * @param nums: The integer array.
//      * @param target: Target number to find.
//      * @return: The first position of target. Position starts from 0. 
//      */
// int binarySearch(vector<int> &array, int target) {
         
//          // write your code here
//          if(array.empty()) return -1;
         
//          int ret = array.size();
//          int left = 0, right = array.size()-1;
         
//          while (left <= right) {
//              int mid = (left + right) >> 1;
//              if (array[mid] == target) {
//                  ret = min(ret, mid);
//                  right = mid - 1;
//              }
//              if (array[mid] > target) {
//                  right = mid - 1;
//              }
//              if (array[mid] < target) {
//                  left = mid + 1;
//              }
//          }
         
//          if (ret == array.size()) {
//              ret = -1;
//          }
         
//          return ret;
// }
// };


class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
int binarySearch(vector<int> &array, int target) {
         
    if(array.empty()) return -1;
    
    int left=0,right=array.size()-1,mid;
    int ans=array.size();
    
    while(left<=right)
    {
        mid=(left+right)/2;
        if(array[mid]==target) 
        {
        ans=min(ans,mid);
        right=mid-1;
        }
        if(array[mid]<target) left=mid+1;
        if(array[mid]>target) right=mid-1;
    }

    if(ans==array.size()) 
    ans=-1;
    
    return ans;
}

};