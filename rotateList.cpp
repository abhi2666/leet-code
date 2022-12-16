class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* res;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nex = NULL;
        while(curr->next && curr)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        res = prev;
    }
};