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
    ListNode* res;
    void GO(ListNode* prev, ListNode* cur)
    {
        if(!cur)
        {
            res = prev;
            return;
        }
        const auto cur_next = cur->next;
        cur->next = prev;
        GO(cur, cur_next);
    }
    ListNode* reverseList(ListNode* head) {
        GO(nullptr, head);
        return res;
    }
};
