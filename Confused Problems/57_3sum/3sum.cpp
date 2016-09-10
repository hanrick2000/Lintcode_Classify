/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 16-08-14 04:30
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        return threeSumGen(num, 0);
    }
    
    vector<vector<int>>threeSumGen(vector<int>&num, int target) {
        
        vector<vector<int>> allSol;
        
        if(num.size()<3) return allSol;
        sort(num.begin(),num.end());
        
        for(int i=0; i<num.size()-2; i++) {
            
            if(i>0 && num[i]==num[i-1]) continue;
            int left=i+1, right=num.size()-1;
            
            while(left<right) {
                int curSum = num[left]+num[right];
                int curTarget = target-num[i];
                
                if(curSum==curTarget) {
                    
                    vector<int> sol;
                    
                    sol.push_back(num[i]);
                    sol.push_back(num[left]);
                    sol.push_back(num[right]);
                    
                    allSol.push_back(sol);
                    
                    left++;
                    right--;
                    
                    while(num[left]==num[left-1]) left++;
                    while(num[right]==num[right+1]) right--;
                }
                
                else if(curSum<curTarget)
                    left++;
                else
                    right--;
            }
        }
        
        return allSol;
    }
};
