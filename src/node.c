#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "errors.h"

Node* node_create(int val, Node* next)
{
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->next = next;
    node->val = val;
    return node;
}

int node_destroy(Node* node)
{
    if (node == NULL) {
        return NULL_OBJECT_ERROR;
    }
    free(node);
    return SUCCESS;
}

DoubleNode* doubleNodeCreate(int val, DoubleNode* prev, DoubleNode* next)
{
    DoubleNode* node = malloc(sizeof(DoubleNode));
    if (node == NULL) {
        return NULL;
    }
    node->prev = prev;
    node->next = next;
    node->val = val;
    return node;
}

int doubleNodeDestroy(DoubleNode* node)
{
    if (node == NULL) {
        return NULL_OBJECT_ERROR;
    }
    free(node);
    return SUCCESS;
}

RBTreeNode* rbTreeNodeCreate(int key, int val, bool isRed, RBTreeNode* left, RBTreeNode* right)
{
    RBTreeNode* node = malloc(sizeof(RBTreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->left = left;
    node->right = right;
    node->key = key;
    node->val = val;
    node->isRed = isRed;
    return node;
}

int rbTreeNodeDestroy(RBTreeNode* node)
{
    if (node == NULL) {
        return NULL_OBJECT_ERROR;
    }
    free(node);
    return SUCCESS;
}
