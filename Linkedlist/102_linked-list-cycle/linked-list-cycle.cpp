/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/linked-list-cycle
@Language: C++
@Datetime: 16-08-17 21:06
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        
        if(head==NULL || head->next==NULL) return false;
        
        ListNode *fast = head->next;
        ListNode *slow = head;

        while(fast!=NULL && fast->next != NULL)
        {
            if(fast==slow)
            return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return false;
    }
};


