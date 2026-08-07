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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans_dummy = new ListNode();
        // add head into answer
        ans_dummy->next = head;
        ListNode* cur = head->next;
        head->next = nullptr;
        while(cur){
            // add cur node in its place in ans list
            ListNode* cur_ans = ans_dummy->next;
            ListNode* prev_ans = ans_dummy;
            while(cur_ans && cur_ans->val<cur->val){
                prev_ans = cur_ans;
                cur_ans = cur_ans->next;
            }
            prev_ans->next = cur;
            ListNode* next = cur->next;
            cur->next = cur_ans;
            // update ptrs
            cur = next;
        }
        return ans_dummy->next;
    }
};