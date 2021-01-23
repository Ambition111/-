/**
 * 		struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p_max = new ListNode(-1);
        ListNode* p_min = new ListNode(-1);
        ListNode* p_max_tail = p_max;
        ListNode* p_min_tail = p_min;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                p_min_tail->next = head;
                p_min_tail = p_min_tail->next;
            }
            else
            {
                p_max_tail->next = head;
                p_max_tail = p_max_tail->next;
            }
            head = head->next;
        }
        p_min_tail->next = p_max->next;
        p_max_tail->next = nullptr;
        return p_min->next;
    }
};
