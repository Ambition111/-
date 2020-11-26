/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL)     return l2;
    if (l2 == NULL)     return l1;

    struct ListNode *tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (tail == NULL)   return 0;
    struct ListNode *head = tail;

    
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;//tail永远指向新链表的尾
	}

	if (l1 != NULL)
		tail->next = l1;
	if (l2 != NULL)
		tail->next = l2;
    
    return head->next;
}
