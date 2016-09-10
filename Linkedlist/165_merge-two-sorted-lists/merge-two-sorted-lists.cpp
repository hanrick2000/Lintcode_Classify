/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 16-08-22 01:15
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        
        ListNode * dummy = new ListNode (0);
        ListNode * newNode = dummy;
        
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
            newNode->next=l1;
            l1=l1->next;
            }else
            {
            newNode->next=l2;
            l2=l2->next;   
            }
            newNode=newNode->next;
        }
        
        newNode->next = (l2==NULL) ? l1 : l2;
        
        return dummy->next;
    }
};