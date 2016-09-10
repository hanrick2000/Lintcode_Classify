/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-08-14 04:43
*/

// class Solution {
// public:    
//     /**
//      * @param numbers: Give an array numbers of n integer
//      * @param target: An integer
//      * @return: return the sum of the three integers, the sum closest target.
//      */
//     int threeSumClosest(vector<int> nums, int target) {
//         // write your code here
//     }
// };

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3) return INT_MAX;
        sort(num.begin(),num.end());
        int minDiff = INT_MAX;
        for(int i=0; i<num.size()-2; i++) {
            int left=i+1, right = num.size()-1;
            while(left<right) {
                int diff = num[i]+num[left]+num[right]-target;
                if(abs(diff)<abs(minDiff)) minDiff = diff;
                if(diff==0) 
                    break;
                else if(diff<0)
                    left++;
                else
                    right--;
            }
        } 
        return target+minDiff;
    }
};
