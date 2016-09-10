/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: C++
@Datetime: 16-06-20 05:32
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        
        if(head==NULL || n==0) return NULL;
    
        ListNode *slow = head;
        ListNode *fast = head;


        // fast is n-step ahead.
        while (n-- > 0) {
            fast = fast->next;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};


