/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-07-12 04:02
*/

//Method one: make two demension into one demension:O(log(n*m))
// class Solution {
// public:
//     /**
//      * @param matrix, a list of lists of integers
//      * @param target, an integer
//      * @return a boolean, indicate whether matrix contains target
//      */
//     bool searchMatrix(vector<vector<int> > &matrix, int target) {
//         // write your code here
        
//         if(matrix.empty()||matrix[0].empty()) return false;
//         int row=matrix.size();
//         int col=matrix[0].size();
//         int bgn=0,end=row*col-1,mid;
        
//         while(bgn<=end)
//         {
//             mid=(bgn+end)/2;
//             if(matrix[mid/col][mid%col]==target) return true;
//             else if(matrix[mid/col][mid%col]>target)end=mid-1;
//             else bgn=mid+1;
//         }
        
//         return false;
//     }
// };

// // -- Method two: do the row first and then do the col;

// class Solution {
// public:
//     /**
//      * @param matrix, a list of lists of integers
//      * @param target, an integer
//      * @return a boolean, indicate whether matrix contains target
//      */
//     bool searchMatrix(vector<vector<int> > &matrix, int target) {
//         // write your code here
        
//         if(matrix.empty()||matrix[0].empty()) return false;
//         int row=matrix.size();
//         int col=matrix[0].size();
//         int bgn=0,end=row-1,mid;
        
//         while(bgn<=end)
//         {
//             mid=(bgn+end)/2;
//             if(matrix[mid][0]==target) return true;
//             else if(matrix[mid][0]<target)bgn=mid+1;
//             else end=mid-1;
//         }
        
//         if(bgn==0) return false;
//         row=bgn-1;
//         bgn=0;
//         end=col-1;
        
//         while(bgn<=end)
//         {
//             mid=(bgn+end)/2;
//             if(matrix[row][mid]==target) return true;
//             else if(matrix[row][mid]<target)bgn=mid+1;
//             else end=mid-1;
//         }
        
        
//         return false;
//     }
// };


class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
bool searchMatrix(vector<vector<int> > &matrix, int target) {
// write your code here
        
  if(matrix.empty()||matrix[0].empty()) return false;
  
  int row=matrix.size();
  int col=matrix[0].size();
  
  int left=0,right=row-1,mid;
  
  //do the row search
  
  while(left<=right)
  {
      mid=(left+right)>>1;
      
      if(matrix[mid][0]==target) return true;
      
      if(matrix[mid][0]<target) left=mid+1;
      
      if(matrix[mid][0]>target) right=mid-1;
  }
  
  
  //mid row has the element
  //and the element is not the first element in that row
  //left=mid+1; is the break condition
  
  //do the column
  
  if(left==0) return false;
  row=left-1;
  left=0;
  right=col-1; 
 
  while(left<=right)
  {
      mid=(left+right)>>1;
      
      if(matrix[row][mid]==target) return true;
      
      if(matrix[row][mid]<target) left=mid+1;
      
      if(matrix[row][mid]>target) right=mid-1;
      
  }
  
  return false;
}


};
