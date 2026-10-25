#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include "errors.h"

Node* nodeCreate(void* value, size_t valueSizeInBytes, Node* next)
{
    Node* node = malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    node->next = next;
    node->value = malloc(valueSizeInBytes);
    if (!node->value)
    {
        free(node);
        return NULL;
    }
    memcpy(node->value, (char*) value, valueSizeInBytes);
    return node;
}

int nodeDestroy(Node* node)
{
    if (node == NULL)
        return NULL_OBJECT_ERROR;
    if (node->value)
        free(node->value);
    free(node);
    return SUCCESS;
}

DoubleNode* doubleNodeCreate(void* value, size_t valueSizeInBytes, DoubleNode* prev, DoubleNode* next)
{
    DoubleNode* node = malloc(sizeof(DoubleNode));
    if (!node)
        return NULL;
    node->prev = prev;
    node->next = next;
    node->value = malloc(valueSizeInBytes);
    if (!node->value) {
        free(node);
        return NULL;
    }
    memcpy(node->value, (char*) value, valueSizeInBytes);
    return node;
}

int doubleNodeDestroy(DoubleNode* node)
{
    if (node == NULL)
        return NULL_OBJECT_ERROR;
    if (node->value)
        free(node->value);
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
