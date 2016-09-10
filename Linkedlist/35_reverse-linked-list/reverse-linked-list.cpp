/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: C++
@Datetime: 16-08-24 08:23
*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
// Method one : iteration

    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        
        while (head) {
            
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
// //Method two : recursion;
// ListNode *reverse(ListNode *head) {
     
//         if (head == NULL || head->next == NULL) {
// 			return head;// when p1 reach the end and p2 , p1 will gain the end address;
// 		}

// 		ListNode *p1 = head->next;// make the p1 always one ahead of the head;
// 		ListNode *p2 = reverse(p1); // until the p1 reach the end and p2=p1;
// 		//At last: p2==p1 becasue p1->next=NULL;
// 		//Each time p2 will point to the end of the list;
		
// 		head->next = NULL;
// 		p1->next = head;
		
// 		//Each time: make the head->next not point to the p1 and make p1->next to the head;

// 		return p2;
// }

    
};
