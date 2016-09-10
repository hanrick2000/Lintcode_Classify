/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 16-06-25 21:34
*/

// class Solution {
// public:
//     /**
//      * @param n: An integer.
//      * return : An array storing 1 to the largest number with n digits.
//      */
    
//     // void recursion(int st,int largest,vector<int>& results) 
//     // {
     
//     //  if (st >=largest)  return;
      
//     //   results.push_back(st);
//     //   recursion(st + 1,largest,results);
//     // }
    
//     // int power(int m,int n)
//     // {
//     //     if(n==0) return 1;
        
//     //     int start=1;
        
//     //     while(n)
//     //     {    
//     //     start*=m;
//     //     n--;
//     //     }
//     //     return start;
//     // }
    
//     // vector<int> numbersByRecursion(int n) {
        
//     //     // write your code here
        
//     //     vector<int> res;
        
//     //     for(int i=1;i<=n;i++)
//     //     recursion(power(10,i-1),power(10,i),res);
        
//     //     return res;
//     // }
    
    
// };

class Solution {  
private:  
  
    void numbersByRecursionHelper(int n, vector<int> &retVector)  
    {  
        if (n == 0)  
            return;  
              
        numbersByRecursionHelper(n-1, retVector);  
        int curSize = retVector.size();  
          
        for (int i=pow(10, n-1); i<=9*pow(10, n-1); i+=pow(10,n-1))  
        {  
            for (int idx=0; idx<curSize; idx++)  
            {  
                retVector.push_back(i+retVector[idx]);  
            }  
        }  
    }  
      
public:  
    /** 
     * @param n: An integer. 
     * return : An array storing 1 to the largest number with n digits. 
     */  
       
    vector<int> numbersByRecursion(int n) {  
        // write your code here  
        vector<int> retVector;  
        retVector.push_back(0);  
          
        numbersByRecursionHelper(n, retVector);  
  
        vector<int> res(retVector.begin()+1, retVector.end());  
          
        return res;  
    }  
};