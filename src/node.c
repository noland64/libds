#include <stdlib.h>
#include "node.h"
#include "errors.h"

Node* node_create(int val, Node* next)
{
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}

int node_destroy(Node* node)
{
    if (node == NULL)
        return NULL_OBJECT_ERROR;
    free(node);
    return 1;
}