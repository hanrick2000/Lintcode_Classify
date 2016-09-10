/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays-ii
@Language: C++
@Datetime: 16-08-31 08:59
*/

/*
这道题是之前那道Intersection of Two
Arrays的拓展，不同之处在于这道题允许我们返回重复的数字，
而且是尽可能多的返回，之前那道题是说有重复的数字只返回一个就行。
那么这道题我们用哈希表来建立nums1中字符和其出现个数之间的映射, 
然后遍历nums2数组，如果当前字符在哈希表中的个数大于0，
则将此字符加入结果res中，然后哈希表的对应值自减1.
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
        
//         unordered_map<int,int>m;
//         vector<int> res;
//         for(auto a : nums1) m[a]++;
//         for(auto a : nums2)
//         {
//             if(m[a]-- > 0) res.push_back(a);
//         }
        
//         return res;
//     }
// };

/*
再来看一种方法，这种方法先给两个数组排序，
然后用两个指针分别指向两个数组的起始位置，
如果两个指针指的数字相等，则存入结果中，两个指针均自增1，
如果第一个指针指的数字大，则第二个指针自增1，反之亦然，
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i; ++j;
            } else if (nums1[i] > nums2[j]) {
                ++j;
            } else {
                ++i;
            }
        }
        return res;
    }
};