/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/rotate-list
@Language: C++
@Datetime: 16-08-22 05:41
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(k<1 || !head) return head;
        
        ListNode *p = head;
        int len=1;
        //Get the list's length
        while(p->next)
        {
            p=p->next;
            len++;
        }
        
        //Connect the head to the tail;
        
        p->next = head;
        
        // 实际旋转的次数为: k%len;
        k = len - k%len; // 倒数第k+1个节点: k=len-k%len;
        
        while(k>0)
        {
            p=p->next;
            k--;
        }// p will point to the 顺数k（倒数第k+1个节点）
        
        head = p->next;//倒数第k个节点为新的head
        p->next=NULL;//倒数第k+1个节点与倒数第k个节点断开
        
        return head;
    }
};



/*
1. 将原list的头尾相连。
2. 找到倒数第k+1个节点，并将它与倒数第k个节点断开。而倒数第k个节点为新的head。在1中找list的尾时已经计算出了list的总长n。从尾部开始走n-k步即为该点。
*/

/*
corner case：
1. k<=0 || head == NULL，直接返回。
2. k>= L，L为list总长。对于例子中的list，当k=5时旋转后又回到原来状态。所以实际旋转的次数为k%L。
*/