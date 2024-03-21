/**
 * File: list_node.h
 * Created Time: 2023-01-09
 * Author: Reanon (793584285@qq.com)
 */

#ifndef LIST_NODE_H
#define LIST_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

/* 鏈結串列節點結構體 */
typedef struct ListNode {
    int val;               // 節點值
    struct ListNode *next; // 指向下一節點的引用
} ListNode;

/* 構造函式，初始化一個新節點 */
ListNode *newListNode(int val) {
    ListNode *node;
    node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

/* Generate a linked list with an array */
ListNode *arrToLinkedList(const int *arr, size_t size) {
    if (size <= 0) {
        return NULL;
    }

    ListNode *dummy = newListNode(0);
    ListNode *node = dummy;
    for (int i = 0; i < size; i++) {
        node->next = newListNode(arr[i]);
        node = node->next;
    }
    return dummy->next;
}

/* Get a list node with specific value from a linked list */
ListNode *getListNode(ListNode *head, int val) {
    while (head != NULL && head->val != val) {
        head = head->next;
    }
    return head;
}

/* Free the memory allocated to a linked list */
void freeMemoryLinkedList(ListNode *cur) {
    // 釋放記憶體
    ListNode *pre;
    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
        free(pre);
    }
}

#ifdef __cplusplus
}
#endif

#endif // LIST_NODE_H
