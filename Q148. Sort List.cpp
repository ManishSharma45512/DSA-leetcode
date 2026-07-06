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

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

                                                                                       XXXXXXXXXXXXXXXXXXXXXXXXXXX

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



class Solution {
public:
    void countingSort(vector<int>& arr) {
        if (arr.empty()) return;

        
        int minVal = arr[0];
        int maxVal = arr[0];
        for (int num : arr) {
            if (num > maxVal) maxVal = num;
            if (num < minVal) minVal = num;
        }

        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);

        
        for (int num : arr) {
            count[num - minVal]++;
        }

        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[index] = i + minVal; 
                index++;
                count[i]--;
            }
        }
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head; // Base case

        ListNode* temp = head;
        vector<int> arr;

        while(temp != nullptr) { // O(n) TC
            arr.push_back(temp->val);
            temp = temp->next;
        } // list is ready in array

        countingSort(arr); // count sorting algorithm of O(n) TC

        // arr is now sorted in ascending order (e.g., [1, 2, 3, 4])

        ListNode* sorted = new ListNode(0);
        ListNode* mainHead = sorted;

        
        for(int i = 0; i < arr.size(); i++) { // O(n) TC
            sorted->next = new ListNode(arr[i]);
            sorted = sorted->next;
        }

        ListNode* actualHead = mainHead->next;
        delete mainHead; // Memory cleanup: Free the dummy node memory

        return actualHead;
    }
};
