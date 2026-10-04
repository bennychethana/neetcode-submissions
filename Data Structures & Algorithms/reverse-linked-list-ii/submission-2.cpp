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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        right = right-left;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* prev = dummy;
        while(left--){
            prev = cur;
            cur = cur->next;
        }
        ListNode* start_left = prev;
        ListNode* start = cur;
        prev = cur;
        cur = cur->next;
        while(right--){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        start_left->next = prev;
        start->next = cur;
        return dummy->next;
    }
};