#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
typedef struct DoubleNode DoubleNode;
typedef struct TreeNode TreeNode;

struct Node {
    int val;
    Node* next;
};

struct DoubleNode {
    int val;
    DoubleNode* next;
    DoubleNode* prev;
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

Node* node_create(int val, Node* next);
int node_destroy(Node* node);

// doubleNodeCreate(int val, DoubleNode* prev, DoubleNode* next)
// Create and allocate memory for new DoubleNode
// Return newly created DoubleNode, or NULL in the event of error
DoubleNode* doubleNodeCreate(int val, DoubleNode* prev, DoubleNode* next);

// doubleNodeDestroy(Deque* deque)
// Destroy node and free allocated memory
// Return success/error code
int doubleNodeDestroy(DoubleNode* node);

#endif