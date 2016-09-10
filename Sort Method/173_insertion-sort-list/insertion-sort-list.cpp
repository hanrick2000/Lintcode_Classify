/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-08-17 20:38
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
//      * @return: The head of linked list.
//      */
//     ListNode *insertionSortList(ListNode *head) {
//         // write your code here
//      ListNode * dummy = new ListNode(0);
//      ListNode * cur = head;
     
//      while(cur!=NULL)
//      {
//      ListNode *pre=dummy;    
//      while(pre->next !=NULL && pre->next->val <cur->val)
//      {
//          pre=pre->next;
//      }
//      ListNode * temp=cur->next;
//      cur->next =pre->next;
//      pre->next =cur;
//      cur=temp;
//      }
        
//      return dummy->next;
//     }
// };



class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
    ListNode *cur = head;
        while (cur != NULL) {
            if (cur->next != NULL && cur->next->val < cur->val) {
                ListNode *pre = dummy;
                // find insert position for smaller(cur->next)
                while (pre->next != NULL && pre->next->val <= cur->next->val) {
                    pre = pre->next;
                }
                // insert cur->next after pre
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            } else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};