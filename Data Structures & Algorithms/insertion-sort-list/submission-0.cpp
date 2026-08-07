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
        ListNode* cur_ans = new ListNode();
        ans_dummy = cur_ans;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = head;
        ListNode* prev = dummy;
        ListNode* min_prev = dummy;
        int min = INT_MAX;
        ListNode* min_node = nullptr;
        ListNode* min_next = nullptr;
        int n = 0;
        while(cur){
            cur = cur->next;
            n++;
        }
        cur = head;
        while(n--){
            // find current min
            while(cur){
                if(cur->val<=min){
                    min = cur->val;
                    min_node = cur;
                    min_prev = prev;
                    min_next = min_node->next;
                }
                prev = cur;
                cur = cur->next;
            }
            // remove min from list
            min_prev->next = min_next;
            min_node->next = nullptr;
            // add min into ans
            cur_ans->next = min_node;
            cur_ans = cur_ans->next;
            // reset cur,prev...
            cur = dummy->next;
            prev = dummy;
            min = INT_MAX;
            min_next = nullptr;
            min_node = nullptr;
            min_prev = nullptr;
        }
        return ans_dummy->next;
    }
};




