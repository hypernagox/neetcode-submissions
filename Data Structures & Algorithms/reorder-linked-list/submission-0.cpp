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
    ListNode* GO(ListNode* target)
    {
        if(!target)return nullptr;
        ListNode* node = target;
        ListNode* prev = nullptr;
        int cnt = 0;
        while(node)
        {
            ++cnt;
            const auto next = node->next;
            if(!next)
            {
                if(cnt == 1)
                {
                    return nullptr;
                }
                break;
            }
            prev = node;
            node = next;
        }
        if(prev)
        {
            prev->next = nullptr;
        }
        node->next = target->next;
        target->next = node;
        return node->next;
    }
    void reorderList(ListNode* head) 
    {
        ListNode* node = head;
        while(node)
        {
            const auto next = GO(node);
            node = next;
        }
    }
};
