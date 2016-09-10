/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: C++
@Datetime: 16-08-17 20:17
*/

// /**
//  * Definition of ListNode
//  * class ListNode {
//  * public:
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int val) {
//  *         this->val = val;
//  *         this->next = NULL;
//  *     }
//  * }
//  */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        
        if(head==NULL) return NULL;
        
        int len=0;
        ListNode *node = head;
        while(node!=NULL)
        {
            node=node->next;
            len++;
        }
        
        return sortListHelper(head,len);
    }

private:
  
    ListNode * sortListHelper(ListNode*head,const int length)
    {
        if((head==NULL)||(length<=0)) return head;
        
        ListNode * midNode = head;
        
        int count=1;
        
        while(count<length/2)
        {
            midNode=midNode->next;
            count++;
        }
        
        ListNode *rList=sortListHelper(midNode->next,length-length/2);
        //Note: length-length/2 != length/2; The length can also be odd number;
        midNode->next=NULL;
        ListNode *lList=sortListHelper(head,length/2);
    
        return mergeList(lList,rList);
    }
    
    ListNode * mergeList(ListNode*l1,ListNode*l2)
    {
        ListNode * dummy = new ListNode(0);
        ListNode * lastNode = dummy;
        
        while((l1!=NULL)&&(l2!=NULL))
        {
            if(l1->val < l2->val)
            {
                lastNode->next=l1;
                l1=l1->next;
            }else{
                lastNode->next=l2;
                l2=l2->next;
            }
            lastNode=lastNode->next;
        }
        
        lastNode->next=(l1!=NULL)?l1:l2;
        
        return dummy->next;
    }
    
};






