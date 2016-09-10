/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list
@Language: C++
@Datetime: 16-09-06 08:20
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
// class Solution {
// public:
//     /**
//      * @param root: The root of tree
//      * @return: the head of doubly list node
//      */
//     DoublyListNode* bstToDoublyList(TreeNode* root) {
//         // Write your code here
        
//         DoublyListNode * head = new DoublyListNode(0);
//         DoublyListNode * preNode = new DoublyListNode(0);

//         bstToDoublyList(root,preNode,head);
        
//         return head;
        
//     }
    
//     void bstToDoublyList(TreeNode* root,DoublyListNode* preNode,DoublyListNode* head)
//     {
//         if(root == NULL) return;
        
//         bstToDoublyList(root->left,preNode,head);
//         DoublyListNode *temp = new DoublyListNode(root->val);
        
//         if (preNode == NULL) {
//           head = temp;
//         } else {
//           temp->prev = preNode;
//           preNode->next = temp;
//         }
//         preNode = temp;
      
//         bstToDoublyList(root->right,preNode,head);
//     }
// };


class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        DoublyListNode *prev = nullptr, *head = nullptr;
        treeToDoublyList(root, &prev, &head);
        return head;
    }

    void treeToDoublyList(TreeNode *p, DoublyListNode **prev, DoublyListNode **head) {
      if (!p) {
          return;
      }
      treeToDoublyList(p->left, prev, head);
      DoublyListNode *root = new DoublyListNode(p->val);
      if (!*prev) {
          *head = root;
      } else {
          root->prev = *prev;
          (*prev)->next = root;
      }
      *prev = root;
      treeToDoublyList(p->right, prev, head);
    }
};


