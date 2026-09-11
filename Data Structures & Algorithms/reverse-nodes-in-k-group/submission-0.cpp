/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* f(ListNode* node, int k){ // reverse k & return head; if k not there, dont do anything
        if(!node) return nullptr;
        ListNode* cur = node;
        for(int i=0;i<k-1;i++){
            cur = cur->next;
            if(!cur) return node;
        }
        // reverse k nodes
        ListNode* prev = node;
        cur = node->next;
        for(int i=0;i<k-1;i++){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        // attach future
        node->next = f(cur,k);
        return prev; // new head of current grp
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return f(head,k);
    }
};
















