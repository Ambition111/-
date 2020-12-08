/*
	给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
	返回删除后的链表的头节点。

	注意：此题对比原题有改动
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

    phead->next = head;     //定义哑节点后继指向头

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
