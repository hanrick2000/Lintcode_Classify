/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-08-13 17:54
*/

//Has some problems--might not be passed;

// class Solution {
// public:
//     /*
//      * @param numbers : An array of Integer
//      * @param target : target = numbers[index1] + numbers[index2]
//      * @return : [index1+1, index2+1] (index1 < index2)
//      */
//     vector<int> twoSum(vector<int> &nums, int target) {
//         // write your code here
        
//         int left=0;
//         int right=nums.size()-1;
//         vector<int> res;
//         sort(nums.begin(),nums.end());
        
//         while(left<=right)
//         {
//           if(nums[left]+nums[right]==target)
//           {
//           res.push_back(left+1);
//           res.push_back(right+1);
//           }
          
//           else if(nums[left]+nums[right]>target)
//           right--;
//           else if(nums[left]+nums[right]<target)
//           left++;
          
//           while(nums[left]==nums[left+1])left++;
//           while(nums[right]==nums[right-1])right--;
//         }
        
//         return res;
//     }
// };

//Method two;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
        
//         vector<int> num = numbers; // Before the sorting:numbers;After sorting:num;
        
//         std::sort(num.begin(), num.end());  // O[nlog[n]]; Array is from the small to the big;
          
//         int length = numbers.size();  
//         int left = 0;  
//         int right = length - 1;  
//         int sum = 0;  
          
//         vector<int> index;  // Array -- store the return values
          
//         // while + for : O[n*log[n]]  
        
//         while(left < right)  // O[log[n]]; for:O[n]
//         {  
//             sum = num[left] + num[right]; // add the smallest and the biggest 
              
//             if(sum == target)  
//             {  

//                 for(int i = 0; i < length; ++i) // o[n] 
//                 {  
//                     if(numbers[i] == num[left])  
//                     {  
//                         index.push_back(i+1);//Give the i to the index array;
//                     }  
//                     else if(numbers[i] == num[right])  
//                     {  
//                         index.push_back(i+1);//Give the i to the index array;
//                     }  
//                     // if(index.size() == 2)  
//                     // {  
//                     //     break;  
//                     // }  
//                 }  
//                 break;  
//             }  
//             else if(sum > target)  
//             {  
//                 --right;  
//             }  
//             else  
//             {  
//                 ++left;  
//             }  
//         }  
          
//         return index;  
//     }  
// };

//Method three;

class Solution
{
public:   
vector<int> twoSum(vector<int> &numbers, int target) {  
    vector<int> answer;  
    map<int, int> numMap;  
    for (int i = 0; i < numbers.size(); i++)  
        if (numMap.find(target - numbers[i]) != numMap.end()) 
        // Means find something in the map;
        {  
            answer.push_back(numMap[target - numbers[i]]+1);  
            answer.push_back(i+1);  
            return answer;  
        }  
        else numMap[numbers[i]] = i;  
  
    return answer;  
}  
};
