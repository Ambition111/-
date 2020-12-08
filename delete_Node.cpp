/*
	�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣
	����ɾ����������ͷ�ڵ㡣

	ע�⣺����Ա�ԭ���иĶ�
*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (phead == NULL)      return NULL;

    phead->next = head;     //�����ƽڵ���ָ��ͷ

    struct ListNode* p = phead;
    while (head != NULL)
    {
        if (head->val == val)
        {
            p->next = head->next;
        }
        p = p->next;
        head = head->next;
    }
    return phead->next;
}
