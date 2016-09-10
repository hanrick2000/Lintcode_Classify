/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 16-08-18 18:18
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code 
        if(head==NULL) return NULL;
        
        RandomListNode *dummy = new RandomListNode(0);
        RandomListNode *curNode = dummy;
        unordered_map<RandomListNode*, RandomListNode *> randomMap;
        
        while(head!=NULL)
        {
            //link newNode to the new list
            RandomListNode*newNode = new RandomListNode(head->label);
            curNode->next=newNode;
            
            //map old node head to newNode;
            randomMap[head]=newNode;
            
            //copy old node random pointer
            newNode->random=head->random;
            
            head=head->next;
            curNode=curNode->next;
        }
        
        //re-mapping old random node to new node
        curNode = dummy->next;
        
        while(curNode!=NULL)
        {
            if(curNode->random !=NULL)
              curNode->random = randomMap[curNode->random];
        
            curNode=curNode->next;
        }
     
        return dummy->next;
    }
    
};