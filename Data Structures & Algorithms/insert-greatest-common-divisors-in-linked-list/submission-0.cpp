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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        while(cur && cur->next){
            ListNode* new_node = new ListNode(gcd(cur->val,cur->next->val));
            ListNode* next = cur->next;
            cur->next = new_node;
            new_node->next = next;
            cur = next;
        }
        return dummy->next;
    }
};