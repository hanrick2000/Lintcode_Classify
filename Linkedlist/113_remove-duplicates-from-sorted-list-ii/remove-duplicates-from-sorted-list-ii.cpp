/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list-ii
@Language: C++
@Datetime: 16-06-20 06:55
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (!head ||!head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next && head->next->next) {
            if (head->next->val == head->next->next->val) {
                int val = head->next->val;
                while (head->next && head->next->val == val) {
                    ListNode* temper = head->next;
                    head->next = head->next->next;
                    delete temper;
                    
                }
            } else {
                head = head->next;
            }
        }
        return dummy->next;
    }
};