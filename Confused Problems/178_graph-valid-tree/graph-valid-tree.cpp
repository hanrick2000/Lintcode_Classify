/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/graph-valid-tree
@Language: C++
@Datetime: 16-08-29 19:02
*/

/*
我们知道如果是树的话，所有的节点必须是连接的，也就是说必须是连通图，
而且不能有环，所以我们的焦点就变成了验证是否是连通图和是否含有环。
*/
/*
我们首先用DFS来做，根据pair来建立一个图的结构，用邻接链表来表示，
还需要一个一位数组v来记录某个节点是否被访问过，然后我们用DFS来搜索节点0，遍历的思想是，
当DFS到某个节点，先看当前节点是否被访问过，如果已经被访问过，说明环存在，直接返回false，
如果未被访问过，我们现在将其状态标记为已访问过，
然后我们到邻接链表里去找跟其相邻的节点继续递归遍历，
注意我们还需要一个变量pre来记录上一个节点，以免回到上一个节点，
这样遍历结束后，我们就把和节点0相邻的节点都标记为true，
然后我们在看v里面是否还有没被放过的节点，
如果有，则说明图不是完全连通的，返回false，反之返回true
*/
// DFS
// class Solution {
// public:
//     bool validTree(int n, vector<pair<int, int>>& edges) {
//         vector<vector<int>> g(n, vector<int>());
//         vector<bool> v(n, false);
//         for (auto a : edges) {
//             g[a.first].push_back(a.second);
//             g[a.second].push_back(a.first);
//         }
//         if (!dfs(g, v, 0, -1)) return false;
//         for (auto a : v) {
//             if (!a) return false;
//         }
//         return true;
//     }
//     bool dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
//         if (v[cur]) return false;
//         v[cur] = true;
//         for (auto a : g[cur]) {
//             if (a != pre) {
//                 if (!dfs(g, v, a, cur)) return false;
//             }
//         }
//         return true;
//     }
// };


// // BFS
// class Solution {
// public:
//     bool validTree(int n, vector<pair<int, int>>& edges) {
//         vector<unordered_set<int>> g(n, unordered_set<int>());
//         unordered_set<int> v;
//         queue<int> q;
//         q.push(0);
//         v.insert(0);
//         for (auto a : edges) {
//             g[a.first].insert(a.second);
//             g[a.second].insert(a.first);
//         }
//         while (!q.empty()) {
//             int t = q.front(); q.pop();
//             for (auto a : g[t]) {
//                 if (v.find(a) != v.end()) return false;
//                 v.insert(a);
//                 q.push(a);
//                 g[a].erase(t);
//             }
//         }
//         return v.size() == n;
//     }
// };

// // Union Find
// class Solution {
// public:
//     bool validTree(int n, vector<pair<int, int>>& edges) {
//         vector<int> roots(n, -1);
//         for (auto a : edges) {
//             int x = find(roots, a.first), y = find(roots, a.second);
//             if (x == y) return false;
//             roots[x] = y;
//         }
//         return edges.size() == n - 1;
//     }
//     int find(vector<int> &roots, int i) {
//         while (roots[i] != -1) i = roots[i];
//         return i;
//     }
// };


//Good reference:http://www.cnblogs.com/grandyang/p/5257919.html


//Taken from:http://blog.csdn.net/pointbreak1/article/details/48796691

class Solution{  
public:  
    bool validTree(int n, vector<vector<int>>& edges) {  
        vector<int> root(n, -1);  
        for(int i = 0; i < edges.size(); i++) {  
            int root1 = find(root, edges[i][0]);  
            int root2 = find(root, edges[i][1]);  
            if(root1 == root2)  
                return false;  
            root[root1] = root2;  
        }  
        return edges.size() == n - 1;  
    }  
      
    int find(vector<int> &root, int e) {  
        if(root[e] == -1)  
            return e;  
        else  
            find(root, root[e]);  
    }  
};  







