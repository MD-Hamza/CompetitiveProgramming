// https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        
        ListNode* curr = head;
        int len = 0;

        while (curr) {
            curr = curr->next;
            len++;
        }

        curr = head;
        ListNode* temp;
        ListNode* prev = nullptr;
        ListNode* tail = head;
        ListNode* prevtail = nullptr;
        
        ListNode* out = head;
        

        int c = 0;
        while (curr) {
            if (c == 0 && len - k < 0) {
                if (prevtail) prevtail->next = curr;
                return out;
            }
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            
            c++;

            if (c == k) {
                len -= k;
                c = 0;

                if (prevtail) prevtail->next = prev;
                if (out == head) out = prev;
                
                prevtail = tail;
                tail = curr;
                prev = nullptr;
            }
        }
        
        return out;
    }
};