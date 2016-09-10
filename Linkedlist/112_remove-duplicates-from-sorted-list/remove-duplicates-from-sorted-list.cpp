/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-06-20 07:06
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
//      * @return: head node
//      */
//     ListNode *deleteDuplicates(ListNode *head) {
//         // write your code here
        
//         ListNode* current = head;
//         ListNode* next_next;
        
//         if (current == NULL) {
//             return NULL;
//         }
        
//         while (current->next != NULL) {
            
//              if (current->val == current->next->val) {
//                 next_next = current->next->next;
//                 delete current->next;
//                 current->next = next_next;
//             } else {
//                 current = current->next;
//             }
//         }
        
//         return head;
//     }
// };

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

        while (head && head->next) {
            if (head->val == head->next->val) {
                int val = head->val;
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

// Set the current pointer to the head; remain one element and delete the rest duplicated
// Elements from the linked list;

// If set the current pointer to the head->next and compared head->next with head->next->next;
// All the same elements will be deleted;


