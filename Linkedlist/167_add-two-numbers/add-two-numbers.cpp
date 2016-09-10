/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-08-22 02:23
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     /**
//      * @param l1: the first list
//      * @param l2: the second list
//      * @return: the sum list of l1 and l2 
//      */
//     ListNode *addLists(ListNode *l1, ListNode *l2) {
//         // write your code here
//         int bonus=0;
//         ListNode*dummy = new ListNode(0);
//         ListNode*newNode=dummy;
        
//         while(l1 && l2)
//         {
//             if((l1->val+l2->val+bonus)>9)
//             {
//              newNode->next=new ListNode(l1->val+l2->val+bonus-10);
//              bonus=1;
//             }
            
//             else
//             {
//               newNode->next=new ListNode(l1->val+l2->val+bonus); 
//               bonus=0;
//             }
//             newNode=newNode->next;
//             l1=l1->next;
//             l2=l2->next;
//         }
        
//         newNode->next = (l1==NULL) ? l2 : l1;
        
//         if(newNode->next==l1)
//         {
//         while(bonus)
//         {
//              if(l1->val+bonus>9)
//              {
//              l1->val=l1->val+bonus-10;
//              l1=l1->next;
//              bonus=1;
//              }
//              else
//              {
//              bonus=0;
//              }
//         }
//         }
        
//         if(newNode->next==l2)
//         {
//          while(bonus)
//         {
//              if(l2->val+bonus>9)
//              {
//              l2->val=l2->val+bonus-10;
//              l2=l2->next;
//              bonus=1;
//              }
//              else
//              {
//              bonus=0;
//              }
//         }
//         }
        
//         return dummy->next;
//     }
// };

class Solution {
public:
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        
        ListNode *dummy = new ListNode(0), *p = dummy;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            if(l1) {
                carry+=l1->val;
                l1 = l1->next;
            }
            if(l2) {
                carry+=l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(carry%10);
            carry /= 10;
            p = p->next;
        }
        return dummy->next;
    }
};

//http://bangbingsyb.blogspot.com/2014/11/leetcode-add-two-numbers.html
