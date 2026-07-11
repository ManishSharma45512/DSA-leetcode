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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* endInsert = list2;
        while (endInsert->next != nullptr) {
            endInsert = endInsert->next;
        }

        ListNode* st = list1;
        for (int i = 0; i < a - 1; i++) {
            st = st->next;
        }

        ListNode* end = list1;
        for (int i = 0; i < b; i++) {
            end = end->next;
        }
        end = end->next;

        st->next = list2;
        endInsert->next = end;

        return list1;
    }
};
