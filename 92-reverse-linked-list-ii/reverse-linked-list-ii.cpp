
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == NULL || left - right == 0) {
            return head;
        }
        ListNode* ans = head;
        int count = 1;
        ListNode* left_node = NULL;

        while (count < left) {
            left_node = head;

            head = head->next;
            count++;
        }

        ListNode* temp = head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = curr->next;

        while (count < right) {
            curr->next = prev;
            prev = curr;
            curr = forw;
            forw = forw->next;
            count++;
        }
        temp->next = curr->next;

        if (left_node != NULL) {
            left_node->next = curr;
        } else {
            ans = curr;
        }
        curr->next = prev;

        return ans;
    }
};