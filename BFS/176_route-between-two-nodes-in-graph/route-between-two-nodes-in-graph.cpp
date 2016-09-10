/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/route-between-two-nodes-in-graph
@Language: C++
@Datetime: 16-08-29 18:37
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        
        // source to find the target;
        
        if(s->neighbors.size() == 0) return false;
        if(s==t) return true;
        
        deque<DirectedGraphNode*> bfs;
        
        bfs.push_back(s);
        
        while(bfs.size()>0)
        {
          DirectedGraphNode* curNode = bfs[0];  
          for(int i=0;i<curNode->neighbors.size();i++)    
          {
            if(curNode->neighbors[i] == t) return true;
            else  
              bfs.push_back(curNode->neighbors[i]);
          }
          bfs.pop_front();
        }
        
        return false;
    }
};


//http://blog.csdn.net/martin_liang/article/details/45799451
//http://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/