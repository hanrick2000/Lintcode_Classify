/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-08-26 05:20
*/

// class Solution {
// public:
//     /**
//      * @param grid a boolean 2D matrix
//      * @return an integer
//      */
// int numIslands(vector<vector<bool>>& grid) {
//         // Write your code here
//     if(grid.size() == 0) return 0;
//     int res = 0;
//     vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
    
//     for(int i=0;i<grid.size();i++)
//     {
//             for(int j=0;j<grid[0].size();j++)
//             {
//                 if(grid[i][j]==true && visited[i][j] == false)
//                 {
//                     DFS(grid,visited,i,j);
//                     res++;
//                 }
//             }
//     }
        
//     return res;
// }
    
// void DFS(vector<vector<bool>>& grid,vector<vector<bool>>& visited, int i, int j)
//     {
//         if(grid[i][j] == false || visited[i][j] == true) return;
        
//         visited[i][j] == true;
        
//          if(i<grid.size()-1)   
//             DFS(grid,visited,i+1,j);
//          if(i>0)    
//             DFS(grid,visited,i-1,j);
//          if(j<grid[0].size()-1)    
//             DFS(grid,visited,i,j+1);
//          if(j>0)    
//             DFS(grid,visited,i,j-1);
//     }
// };


class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
int numIslands(vector<vector<bool>>& grid){
    if (grid.empty()) return 0;
    vector<vector<bool>>used(grid.size(),vector<bool>(grid[0].size(), false));
    int count = 0;
        
    for (int i = 0; i < grid.size();i++) {
            for (int j = 0; j < grid[0].size();j++) {
                if (grid[i][j] && !used[i][j]) {
                    findIsland(grid, i, j, used);
                    count++;
                }
            }
    }
    return count;
}

void findIsland(vector<vector<bool>>& grid,int x,int y,vector<vector<bool>> &used) 
{
        if (!grid[x][y] || used[x][y]) {
            return;
        }
        used[x][y] = true;
        
        if (x > 0) {
            findIsland(grid, x - 1, y, used);
        }
        if (x < grid.size() - 1) {
            findIsland(grid, x + 1, y, used);
        }
        if (y > 0) {
            findIsland(grid, x, y - 1, used);
        }
        if (y < grid[0].size() - 1) {
            findIsland(grid, x, y + 1, used);
        }
}

};

//https://github.com/kamyu104/LintCode/blob/master/C%2B%2B/number-of-islands.cpp
