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
    bool hasCycle(ListNode* head) {
        ListNode* curr = head;
        std::unordered_map<ListNode*, int> nodes;
        int val = 0;
        while (curr != NULL) {
            val = nodes[curr];
            if (!val) {
                nodes[curr]++;
                curr = curr->next;
                continue;
            }
            return true;
        }
        return false;
    }
};
