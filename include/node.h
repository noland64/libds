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
void node_destroy(Node* node);
DoubleNode* double_node_create(int val, DoubleNode* prev, DoubleNode* next);
void double_node_destroy(DoubleNode* node);
#endif