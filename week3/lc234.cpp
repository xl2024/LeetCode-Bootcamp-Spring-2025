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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        ListNode *faster = head, *slower = head, *prev = nullptr, *curr = head;
        while(faster != nullptr && faster->next != nullptr){
            faster = faster->next->next;
            slower = slower->next;
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode *lp = prev, *rp = slower;
        if(faster != nullptr){
            rp = slower->next;
        }
        while(lp != nullptr){
            if(lp->val != rp->val){
                return false;
            }
            lp = lp->next;
            rp = rp->next;
        }
        return true;
    }
};