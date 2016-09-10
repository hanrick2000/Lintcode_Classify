/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/wiggle-sort-ii
@Language: C++
@Datetime: 16-06-23 19:28
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        // Write your code here
        
        vector<int> temp=nums;
        
        sort(temp.begin(),temp.end());
        
        int l=nums.size(), k=(l+1)/2-1, j=l-1;
        
        for(int i=0;i<l;i++)
        {
            
            nums[i]= i&1 ? temp[j--]: temp[k--] ;
            
        }
        
    }
};