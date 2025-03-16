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
    void reorderList(ListNode* head) {
        ListNode *faster = head, *slower = head, *prev;
        while(faster != nullptr && faster->next != nullptr){
            faster = faster->next->next;
            prev = slower;
            slower = slower->next;
        }
        if(faster != nullptr){
            prev = slower;
            slower = slower->next;
        }
        prev->next = nullptr;
        prev = nullptr;
        while(slower != nullptr){
            ListNode* next = slower->next;
            slower->next = prev;
            prev = slower;
            slower = next;
        }
        while(prev != nullptr){
            ListNode* next = prev->next;
            prev->next = head->next;
            head->next = prev;
            head = prev->next;
            prev = next;
        }
    }
};