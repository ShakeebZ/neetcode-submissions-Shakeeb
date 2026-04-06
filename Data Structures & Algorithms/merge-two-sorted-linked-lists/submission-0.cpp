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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list1ptr = list1;
        ListNode* list2ptr = list2;
        ListNode* next = NULL;

        if (list1ptr == NULL) {
            next = list2ptr;
            return next;
        } else if (list2ptr == NULL) {
            next = list1ptr;
            return next;
        }
        if (list1ptr->val < list2ptr->val) {
            next = list1ptr;
            list1ptr = list1ptr->next;
        } else {
            next = list2ptr;
            list2ptr = list2ptr->next;
        }

        ListNode* head = next;

        while (list1ptr != NULL || list2ptr != NULL) {
            if (list1ptr == NULL) {
                next->next = list2ptr;
                break;
            } else if (list2ptr == NULL) {
                next->next = list1ptr;
                break;
            }
            if (list1ptr->val < list2ptr->val) {
                next->next = list1ptr;
                list1ptr = list1ptr->next;
            } else {
                next->next = list2ptr;
                list2ptr = list2ptr->next;
            }
            next = next->next;
        }
        return head;
    }
};
