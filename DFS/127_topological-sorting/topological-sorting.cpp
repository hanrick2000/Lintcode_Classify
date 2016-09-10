/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/topological-sorting
@Language: C++
@Datetime: 16-08-29 04:30
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
//----DFS
// class Solution {
// public:
//     /**
//      * @param graph: A list of Directed graph node
//      * @return: Any topological order for the given graph.
//      */
//     vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
//         // write your code here
//         vector<DirectedGraphNode*> res;
//         if(graph.size() == 0) return res;
        
//         map<DirectedGraphNode*,int>indegree;
//         //Get the indegree of all DirectedGraphNode
//         indeg(graph,indegree);
//         //dfs recursively
//         for(int i=0;i<graph.size();i++)
//         {
//             if(indegree[graph[i]] == 0)
//             dfs(indegree,graph[i],res);
//         }
        
//         return res;
//     }
    
// private:    
   
//     void indeg(vector<DirectedGraphNode*>&graph,map<DirectedGraphNode*,int>&indegree)
//     {
//         for(int i=0;i<graph.size();i++)
//         {
//             /*
// * struct DirectedGraphNode {
//  *     int label;
//  *     vector<DirectedGraphNode *> neighbors;
//  *     DirectedGraphNode(int x) : label(x) {};
//  * };
//             */
//             for(int j=0;j<graph[i]->neighbors.size();j++)
//             {
//                 if(indegree.find(graph[i]->neighbors[j])==indegree.end())
//                 indegree[graph[i]->neighbors[j]] = 1;
//                 else
//                 {
//                     indegree[graph[i]->neighbors[j]]+=1;
//                 }
//             }
            
//         }
//     }
    
//     void dfs(map<DirectedGraphNode*,int>&indegree,DirectedGraphNode*i,vector<DirectedGraphNode*>&ret)
//     {
//         ret.push_back(i);
//         indegree[i]--;
        
//         for(int j=0;j<i->neighbors.size();j++)
//         {
//             indegree[i->neighbors[j]]--;
//             if(indegree[i->neighbors[j]] == 0)
//             dfs(indegree,i->neighbors[j],ret);
//         }
//     }
// };


// ---BFS
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> result;
        if (graph.size() == 0) return result;

        map<DirectedGraphNode*, int> indegree;
        // get indegree of all DirectedGraphNode
        indeg(graph, indegree);
        queue<DirectedGraphNode*> q;
        // bfs
        bfs(graph, indegree, q, result);

        return result;
    }

private:
    /** get indegree of all DirectedGraphNode
     * 
     */
    void indeg(vector<DirectedGraphNode*> &graph, 
                  map<DirectedGraphNode*, int> &indegree) {

        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i]->neighbors.size(); j++) {
                if (indegree.find(graph[i]->neighbors[j]) == indegree.end()) {
                    indegree[graph[i]->neighbors[j]] = 1;
                } else {
                    indegree[graph[i]->neighbors[j]] += 1;
                }
            }
        }
    }

    void bfs(vector<DirectedGraphNode*> &graph, map<DirectedGraphNode*, int> &indegree,
             queue<DirectedGraphNode *> &q, vector<DirectedGraphNode*> &ret) {

        for (int i = 0; i < graph.size(); ++i) {
            if (indegree[graph[i]] == 0) {
                ret.push_back(graph[i]);
                q.push(graph[i]);
            }
        }

        while (!q.empty()) {
            DirectedGraphNode *cur = q.front();
            q.pop();
            for(int j = 0; j < cur->neighbors.size(); ++j) {
                indegree[cur->neighbors[j]]--;
                if (indegree[cur->neighbors[j]] == 0) {
                    ret.push_back(cur->neighbors[j]);
                    q.push(cur->neighbors[j]);
                }
            }
        }
    }
};
