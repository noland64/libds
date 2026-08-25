#include <stdlib.h>
#include "node.h"
#include "errors.h"

Node* node_create(int val, Node* next)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->val = val;
    node->next = next;
    return node;
}

void node_destroy(Node* node)
{
    if (node != NULL) {
        free(node);
    }
}

DoubleNode* double_node_create(int val, DoubleNode* prev, DoubleNode* next)
{
    DoubleNode* node = malloc(sizeof(DoubleNode));
    if (node == NULL) {
        return NULL;
    }
    node->val = val;
    node->prev = prev;
    node->next = next;
    return node;
}

void double_node_destroy(DoubleNode* node)
{
    if (node != NULL) {
        free(node);
    }
}