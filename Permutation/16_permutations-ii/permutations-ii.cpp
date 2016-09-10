/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/permutations-ii
@Language: C++
@Datetime: 16-07-12 03:07
*/

// class Solution {
// public:
//     /**
//      * @param nums: A list of integers.
//      * @return: A list of unique permutations.
//      */
//     vector<vector<int>> permuteUnique(vector<int> &num) {
        
//         // write your code here
//         vector<vector<int>> allPer;
//         if(num.empty()) return allPer;
//         sort(num.begin(),num.end());
//         vector<int> per;
//         vector<bool> used(num.size(),false);
//         findPerUniq(num, used, per, allPer);
//         return allPer;
//     }
    
// void findPerUniq(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
//         if(per.size()==num.size()) {
//             allPer.push_back(per);
//             return;
//         }
        
//         for(int i=0; i<num.size(); i++) {
//             if(used[i]) continue;
//             if(i>0 && num[i]==num[i-1] && !used[i-1]) continue;//Get rid of the same element
//             used[i] = true;
//             per.push_back(num[i]);
//             findPerUniq(num, used, per, allPer);
//             per.pop_back();
//             used[i] = false;
//         }
//     }
// };


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
vector<vector<int>> permuteUnique(vector<int>&num) {
        // write your code here
        vector<vector<int>> res;//for the whole result;
        if(num.empty()) return res;
        
        sort(num.begin(),num.end());//for the unique permutations;
        vector<int> per;//for the temper result;
        
        vector<bool>used(num.size(),false);//check the used number;
        
        findPerUnique(num,used,per,res);
        return res;
    }
    
void findPerUnique(vector<int>&num,vector<bool>&used, vector<int>&per,vector<vector<int>>&res)
{
    if(per.size()==num.size())
    {
        res.push_back(per);
        return;
    }
    
    for(int i=0;i<num.size();i++)
    {
        if(used[i]) continue;
        if(i>0 && num[i]==num[i-1] && !used[i-1]) continue;
        used[i]=true;
        per.push_back(num[i]);
        findPerUnique(num,used,per,res);
        per.pop_back();
        used[i]=false;
    }
    
}

};