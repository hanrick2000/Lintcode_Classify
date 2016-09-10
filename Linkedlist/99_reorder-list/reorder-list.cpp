/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reorder-list
@Language: C++
@Datetime: 16-08-17 20:56
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
// class Solution {
// public:
//     /**
//      * @param head: The first node of linked list.
//      * @return: void
//      */
//     void reorderList(ListNode *head) {
//         // write your code here
        
//         ListNode *dummy= new ListNode(0);
//         dummy->next=head;
        
//         ListNode *l = head;
//         ListNode *r = head;
        
//         while(r->next!=NULL)
//         {
//           r=r->next;
//         }
        
//         //reverse the list at first and then insert each time;
        
//     }
// };


class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (NULL == head || NULL == head->next || NULL == head->next->next) {
            return;
        }

        ListNode *last = head;
        int length = 0;
        while (NULL != last) {
            last = last->next;
            ++length;
        }

        last = head;
        for (int i = 1; i < length - i; ++i) {
            ListNode *beforeTail = last;
            for (int j = i; j < length - i; ++j) {
                beforeTail = beforeTail->next;
            }

            ListNode *temp = last->next;
            last->next = beforeTail->next;
            last->next->next = temp;
            beforeTail->next = NULL;
            last = temp;
        }
    }
};


