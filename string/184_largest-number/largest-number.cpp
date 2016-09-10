/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/largest-number
@Language: C++
@Datetime: 16-08-23 01:20
*/

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    
    // self made comparison
    
    static bool comp(int a, int b)
    {
        string x=to_string(a),y=to_string(b);
        return x+y > y+x;
    }
    //using string type of x+y>y+x to decide the order of x and y. If x+y>y+x is true, x should be put in front; If not, y should be put in front. 
    // (1,20) : 120 < 201 ; thus return (20,1) ;
    
    
    string largestNumber(vector<int> &nums) {
        // write your code here
         
        //sort the nums according to the self made comparison;
        sort(nums.begin(),nums.end(),comp);
        
        //After sorting : (8,4,23,20,1) ;
        
        //convert to string
        string res="";
        
        for(int i=0;i<nums.size();i++)
        {
            res+=to_string(nums[i]);
        }
        
        if(res[0] == '0') res = '0';// if the case : (0,0,0,0)
        return res;
    }
};

//Good reference 1: http://blog.csdn.net/cinderella_niu/article/details/43227221
//Good reference 2: http://xiamenhai.blogspot.com/2015/10/leetcode-largest-number-sort.html

