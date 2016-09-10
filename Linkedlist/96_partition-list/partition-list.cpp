/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-08-17 18:14
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
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        
        if(head==NULL) return NULL;
        
        //We need four marks and learn how to make them together;
        
        ListNode *leftDummy= new ListNode(0);
        ListNode *left= leftDummy;
        ListNode *rightDummy= new ListNode(0);
        ListNode *right= rightDummy;
        ListNode * node=head;
        
        while(node!=NULL)
        {
            if(node->val<x)
            {
              left->next = node;
              left=left->next;
            }else
            {
              right->next = node;
              right =right->next;
            }
           node=node->next;
        }
        
        right->next=NULL;
        left->next=rightDummy->next;
        
        return leftDummy->next;
    }
};




