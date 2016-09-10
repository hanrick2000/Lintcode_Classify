/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 16-06-27 00:20
*/

class Solution {  
public:  
     
// int majorityNumber(vector<int>&nums, int k) {  

// // write your code here  
// //  int i = 0;  
// //  int j = 0;  
// //  int temp = 0;  
// //  int n = 1;  
 
// //  for(i = 0; i < nums.size(); i++)  
// //  {  
// //   for(j = nums.size()-1; j > i; j--)  
// //   {  
// //   if(nums[j] < nums[j-1])  
// //   {  
// //     temp = nums[j];  
// //       nums[j] = nums[j-1];  
// //     nums[j-1] = temp;  
// //   }  
// //   }  
// //  }  
//  sort(nums.begin(),nums.end());
 
//  int n=1;
 
//  for(int i=0;i<nums.size();i++)  
//  {  
//   if(nums[i] == nums[i+1]) n++; 
//   else  
//   {  
//      if(n > nums.size()/k) return nums[i]; 
//      n = 1;  
//     }  
//   }  
  
//   }  


int majorityNumber(vector<int> nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> hash;

        for (const auto& i : nums) {
            ++hash[i];
            // Detecting k items in hash, at least one of them must have exactly
            // one in it. We will discard those k items by one for each.
            // This action keeps the same mojority numbers in the remaining numbers.
            // Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.
            if (hash.size() == k) {
                auto it = hash.begin();
                while (it != hash.end()) {
                    if (--(it->second) == 0) {
                        hash.erase(it++);
                    } else {
                        ++it;
                    }
                }
            }
        }

        // Resets hash for the following counting.
        for (auto& it : hash) {
            it.second = 0;
        }

        // Counts the occurrence of each candidate integer.
        for (const auto& i : nums) {
            auto it = hash.find(i);
            if (it != hash.end()) {
                ++it->second;
            }
        }

        // Selects the integer which occurs > n / k times.
        vector<int> ret;
        for (const pair<int, int>& it : hash) {
            if (it.second > static_cast<double>(n) / k) {
                ret.emplace_back(it.first);
            }
        }

        return ret[0];
    }
    
};

//解题思路是先将整个集合中的数据进行排序，然后循环进行比较即可
