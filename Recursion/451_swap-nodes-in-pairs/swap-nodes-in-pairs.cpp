/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: C++
@Datetime: 16-08-26 21:54
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//--Recurision method 
// class Solution {
// public:
//     /**
//      * @param head a ListNode
//      * @return a ListNode
//      */
//     ListNode* swapPairs(ListNode* head) {
//         // Write your code here
//         if(!head || !head->next) return head;
        
//         ListNode * t = head->next;
//         head->next  = swapPairs(head->next->next);
//         t->next = head;
        
//         return t;
//     }
// };

//--Iteration method
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};