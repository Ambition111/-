void deleteNode(struct ListNode* node) {
    struct ListNode* node_next = node->next;

    node->val = node_next->val;
    node->next = node_next->next;

    node_next = NULL;
    
}
