/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-08-18 00:33
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        
        //  ListNode *resList=NULL;
        
        // for(int i=0;i<lists.size();i++)
        //   resList=mergeTwoLists(resList,lists[i]);
        
        // return  resList;
        
        if(lists.empty()) return NULL;
        int end = lists.size()-1;
        while(end>0) {
            int begin = 0;
            while(begin<end) {
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }
    
     ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
     {
         
         if(l1==NULL) return l2;
         if(l2==NULL) return l1;
         if(l1==NULL && l2==NULL) return NULL;
         
         ListNode * dummy =new ListNode(0);
         ListNode * head = dummy;
         
         while(l1 && l2)
         {
             if(l1->val<l2->val) 
               {
               head->next=l1;
               l1=l1->next;
               }
             else
             {
               head->next=l2;
               l2=l2->next;
             }
              
             head=head->next;
         }
         
        head->next = l1 ? l1 : l2;
        
        return dummy->next; 
     }
};


