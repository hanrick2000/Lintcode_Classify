/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/rehashing
@Language: C++
@Datetime: 16-08-29 05:49
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        // write your code here
        int n=hashTable.size();
        int nn=2*n;
        vector<ListNode*> headTable(nn);
        vector<ListNode*> tailTable(nn);
        
        for(int i=0;i<n;i++)
        {
            ListNode *list = hashTable[i];
            while(list!=NULL)
            {
                int indx = list->val % nn;
                
                if(indx<0) indx += nn; 
                
                if(tailTable[indx])
                  tailTable[indx]->next = list;
                tailTable[indx] = list;
                
                if(!headTable[indx]) headTable[indx] = list;
                
                //Getting rid of the previous node
                
                ListNode * t = list;
                list = t->next;
                t->next = NULL;
            }
        }
        
        return headTable;
    }
};
