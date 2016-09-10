/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-06-20 05:24
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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //write your code here

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;


        // fast is n-step ahead.
        while (n-- > 0) {
            fast = fast->next;
        }

        // When fast reaches the end, slow must be nth to last node.
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *node_to_delete = slow->next;
        slow->next = slow->next->next;
        delete node_to_delete;


        return dummy->next;
    
    }
};



