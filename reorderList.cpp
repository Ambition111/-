/*
	����һ��������?L��L0��L1������Ln-1��Ln ��
	�����������к��Ϊ�� L0��Ln��L1��Ln-1��L2��Ln-2����
	�㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻��

	ʾ��1�� 
	�������� 1->2->3->4, ��������Ϊ 1->4->2->3.
	
	ʾ�� 2:
	�������� 1->2->3->4->5, ��������Ϊ 1->5->2->4->3.
*/ 
class Solution {
public:
    ListNode* FindMidNode(ListNode* head)   //���ÿ���ָ���ҵ��м�ڵ�
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

    ListNode* reverseList(ListNode* head)   //��ת����
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

        ListNode* mid = FindMidNode(head);  //�ҵ��м�ڵ�
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }
};
