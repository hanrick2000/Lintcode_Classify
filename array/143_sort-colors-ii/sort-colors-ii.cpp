/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-colors-ii
@Language: C++
@Datetime: 16-08-21 16:25
*/

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        //sort(colors.begin(),colors.end());//O(nlog(n));
        
        // Construct the color array and distribute again
        
        vector<int>count(k+1);
        
        for(int i:colors) count[i]++;//Construct the color array 
        
        int pos=0;
        
        for(int i=1;i<=k;i++)
        {
            while(count[i]>0)
            {
                colors[pos++]=i;//distribute again
                count[i]--;
            }
        }
        
    }
};