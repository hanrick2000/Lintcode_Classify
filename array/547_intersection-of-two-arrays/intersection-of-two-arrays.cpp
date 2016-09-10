/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-08-31 08:50
*/

// class Solution {
// public:
//     /**
//      * @param nums1 an integer array
//      * @param nums2 an integer array
//      * @return an integer array
//      */
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         // Write your code here
//         /*
//         用set把nums1都放进去，然后遍历nums2的元素，
//         如果在set中存在，说明是公共部分，加入结果的set中，
//         最后再把结果转为vector的形式即可：
//         */
//         set<int> s(nums1.begin(),nums1.end()),res;
//         for(auto a: nums2)
//         {
//             if(s.count(a))
//             res.insert(a);
//         }
//         return vector<int>(res.begin(),res.end());
//     }
// };

/*
我们还可以使用两个指针来做，先给两个数组排序，
然后用两个指针分别指向两个数组的开头，然后比较两个数组的大小，
把小的数字的指针向后移，如果两个指针指的数字相等，
那么看结果res是否为空，如果为空或者是最后一个数字和当前数字不等的话，
将该数字加入结果res中.
*/

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> res;
//         int i = 0, j = 0;
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
//         while (i < nums1.size() && j < nums2.size()) {
//             if (nums1[i] < nums2[j]) ++i;
//             else if (nums1[i] > nums2[j]) ++j;
//             else {
//                 if (res.empty() || res.back() != nums1[i]) {
//                     res.push_back(nums1[i]);
//                 }
//                 ++i; ++j;
//             }
//         }
//         return res;
//     }
// };

/*
我们还可以使用二分查找法来做，思路是将一个数组排序，
然后遍历另一个数组，把遍历到的每个数字在排序号的数组中用二分查找法搜索，
如果能找到则放入结果set中，这里我们用到了set的去重复的特性
，最后我们将set转为vector即可：
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(), nums2.end());
        for (auto a : nums1) {
            if (binarySearch(nums2, a)) {
                res.insert(a);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
    bool binarySearch(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
 
