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
    unordered_set<ListNode*> visited;
    bool GO(ListNode* node)
    {
        if(!node)return true;
        if(!visited.emplace(node).second)return false;
        return GO(node->next);
    }
    bool hasCycle(ListNode* head) 
    {
        return !GO(head);
    }
};
