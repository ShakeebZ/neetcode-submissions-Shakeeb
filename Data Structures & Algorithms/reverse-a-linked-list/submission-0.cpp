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
        ListNode* swapNodes(ListNode* prev, ListNode* curr) {
            if (curr != NULL) {
                ListNode* temp = curr->next;
                curr->next = prev;
                return swapNodes(curr, temp);
            }
            return prev;
        }

        ListNode* reverseList(ListNode* head) {
            if (head == NULL) return NULL;
            ListNode* next = head->next;
            head->next = NULL;
            return swapNodes(head, next);
        }
};