/*
	给定一个单链表?L：L0→L1→…→Ln-1→Ln ，
	将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
	你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换

	示例1： 
	给定链表 1->2->3->4, 重新排列为 1->4->2->3.
	
	示例 2:
	给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/ 
class Solution {
public:
    ListNode* FindMidNode(ListNode* head)   //利用快慢指针找到中间节点
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head)   //反转链表
    {
        if (head == nullptr || head->next == nullptr)   return head;
        ListNode* p = head->next;
        ListNode* q = p->next;
        head->next = nullptr;

        while (p != nullptr)
        {
            p->next = head;
            head = p;
            p = q;
            if (q != nullptr)
                q = q->next;
        }
        return head;
    }

    void mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* p = l1;
        ListNode* q = l2;
        while (l1 != nullptr && l2 != nullptr)
        {
            p = l1->next;
            q = l2->next;

            l1->next = l2;
            l1 = p;

            l2->next = l1;
            l2 = q;
        }
    }
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)   return;

        ListNode* mid = FindMidNode(head);  //找到中间节点
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};
