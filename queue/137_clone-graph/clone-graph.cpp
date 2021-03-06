/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/clone-graph
@Language: C++
@Datetime: 16-08-29 06:56
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

//Note:undirected graph;

// Travsal and construct;

// -- BFS;

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(!node) return NULL;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>ht;
        queue<UndirectedGraphNode*>q;
        q.push(node);
        ht[node] = p2;
        
        while(!q.empty())
        {
            p1 = q.front();
            p2 = ht[p1];
            q.pop();
            for(int i=0;i<p1->neighbors.size();i++)
            {
                UndirectedGraphNode * nb = p1->neighbors[i];
                if(ht.count(nb))
                {
                 p2->neighbors.push_back(ht[nb]);
                }
                else
                {
                UndirectedGraphNode * temp = new UndirectedGraphNode(nb->label);
                p2->neighbors.push_back(temp);
                ht[nb] = temp;
                q.push(nb);
                }
            }
        }
        
        return ht[node];
    }
};