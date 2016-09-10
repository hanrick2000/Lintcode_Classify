/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/trapping-rain-water
@Language: C++
@Datetime: 16-06-26 00:44
*/

// class Solution {
// public:
//     /**
//      * @param heights: a vector of integers
//      * @return: a integer
//      */
//     // int trapRainWater(vector<int> &heights) {
//     //     // write your code here
//     //     int MaxCurrentWater=0;
        
//     //     vector<int>maxleftHeight(heights.size(),0);
//     //     vector<int>maxrightHeight(heights.size(),0);
        
//     //     for(int i=0;i<heights.size();i++)
//     //     {
//     //         for(int j=0;j<i;j++)
//     //         {
//     //         if(heights[j]>maxleftHeight[i])
//     //         maxleftHeight[i]=heights[j];
//     //         }
//     //     }
        
//     //     for(int i=0;i<heights.size();i++)
//     //     {
//     //         for(int j=heights.size()-1;j>i;j--)
//     //         {
//     //         if(heights[j]>maxrightHeight[i])
//     //         maxrightHeight[i]=heights[j];
//     //         }
//     //     }
        
//     //     for(int i=0;i<heights.size();i++)
//     //     {
//     //         MaxCurrentWater+=max(0,min(maxleftHeight[i],maxrightHeight[i])-heights[i]);
//     //     }
        
//     //     return MaxCurrentWater;
//     // }
// };

// MaxCurrentWater=max( min(maxLeftHeight,maxRightHeight)-CurrentHeight,0);

// two pointer:
// class Solution {
// public:
//     int trapRainWater(vector<int> &A) {
//         int n=A.size();
//         if(n<3) return 0;
//         vector<int> leftHeight(n,0);
//         vector<int> rightHeight(n,0);
//         int water = 0;
        
//         for(int i=1; i<n; i++) 
//             leftHeight[i] = max(leftHeight[i-1], A[i-1]);
        
//         for(int i=n-2; i>=0; i--) {
//             rightHeight[i] = max(rightHeight[i+1], A[i+1]);
//             int minHeight = min(leftHeight[i], rightHeight[i]);
//             if(minHeight>A[i]) water += (minHeight - A[i]);
//         }
        
//         return water;
//     }
// };

// Another is using a stack:

class Solution {
public:
int trapRainWater(vector<int> &A) {
        int n=A.size();
        if(n<3) return 0;
        stack<int> s;
        s.push(0);
        int water = 0;
        
        for(int i=1; i<n; i++) {
            if(A[i]>A[s.top()]) {
                int bottom = A[s.top()];
                s.pop();
                while(!s.empty() && A[i]>=A[s.top()]) {
                    water += (A[s.top()]-bottom)*(i-s.top()-1);
                    bottom = A[s.top()];
                    s.pop();
                }
                if(!s.empty()) water += (A[i]-bottom)*(i-s.top()-1);
            }
            s.push(i);
        }
        
        return water;
    }
};


