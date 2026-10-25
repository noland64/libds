#ifndef NODE_H
#define NODE_H

#include <stdbool.h>

typedef struct Node Node;
typedef struct DoubleNode DoubleNode;
typedef struct TreeNode TreeNode;
typedef struct RBTreeNode RBTreeNode;

struct Node {
    Node* next;
    void* value;
};

struct DoubleNode {
    DoubleNode* next;
    DoubleNode* prev;
    void* value;
};

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

struct RBTreeNode {
    RBTreeNode* left;
    RBTreeNode* right;
    int key;
    int val;
    bool isRed;
};

Node* nodeCreate(void* value, size_t valueSizeInBytes, Node* next);
int nodeDestroy(Node* node);

// Create and allocate memory for new DoubleNode
// Return newly created DoubleNode, or NULL in the event of error
DoubleNode* doubleNodeCreate(void* value, size_t valueSizeInBytes, DoubleNode* prev, DoubleNode* next);

// Destroy node and free allocated memory
// Return success/error code
int doubleNodeDestroy(DoubleNode* node);

// Create and allocate memory for new RBTreeNode
// Return newly created RBTreeNode, or NULL in the event of error
RBTreeNode* rbTreeNodeCreate(int key, int val, bool isRed, RBTreeNode* left, RBTreeNode* right);

// Destroy node and free allocated memory
// Return success/error code
int rbTreeNodeDestroy(RBTreeNode* node);
#endif
