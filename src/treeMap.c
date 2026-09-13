#include <stdlib.h>
#include "treeMap.h"
#include "node.h"
#include "errors.h"
#include <stdio.h>

struct TreeMap
{
    RBTreeNode* root;
    int size;
};

// Static helper function prototypes
static void destroyTree(RBTreeNode* root);
static RBTreeNode* insertKey(RBTreeNode* root, int key, int val);
static RBTreeNode* rotateLeft(RBTreeNode* root);
static RBTreeNode* rotateRight(RBTreeNode* root);
static RBTreeNode* flipColors(RBTreeNode* root);
static void printTreeInOrder(RBTreeNode* root);

TreeMap* treeMapCreate(void)
{
    TreeMap* tree = malloc(sizeof(TreeMap));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

int treeMapDestroy(TreeMap* tree)
{
    if (tree == NULL) {
        return NULL_OBJECT_ERROR;
    }
    destroyTree(tree->root);
    free(tree);
    return SUCCESS;
}

int treeMapInsert(TreeMap* tree, int key, int val)
{
    if (tree == NULL) {
        return NULL_OBJECT_ERROR;
    }
    tree->root = insertKey(tree->root, key, val);
    (tree->root)->isRed = false;
    tree->size++;
    return SUCCESS;
}

int treeMapRemove(TreeMap* tree, int key)
{
    if (!tree) {
        return NULL_OBJECT_ERROR;
    }

    return SUCCESS;
}

int treeMapPop(TreeMap* tree, int key)
{
    return 0;
}

int treeMapGet(TreeMap* tree, int key)
{
    if (tree == NULL) {
        return NULL_OBJECT_ERROR;
    }
    RBTreeNode* node = tree->root;
    while ((node) && (node->val != key))
    {
        if (key < node->val) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return (node) ? (node->val) : OUT_OF_BOUNDS_ERROR;
}

int treeMapSize(TreeMap* tree)
{
    return 0;
}

static void destroyTree(RBTreeNode* root)
{
    if (root == NULL) {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

static RBTreeNode* insertKey(RBTreeNode* root, int key, int val)
{
    if (root == NULL) {
        return rbTreeNodeCreate(key, val, true, NULL, NULL);
    }
    else if (key < root->val)
    {
        root->left = insertKey(root->left, key, val);

    }
    else if (key > root->val)
    {
        root->right = insertKey(root->right, key, val);
    }
    else {
        root->val = val;
    }
    //printTreeInOrder(root);
    root = flipColors(root);
    //printTreeInOrder(root);
    root = rotateRight(root);
    //printTreeInOrder(root);
    root = rotateLeft(root);
    //printTreeInOrder(root);



    return root;
}

static RBTreeNode* rotateLeft(RBTreeNode* root)
{
    RBTreeNode* left = root->left;
    RBTreeNode* leftLeft = (left) ? (left->left) : (NULL);
    if ((left) && (leftLeft))
    {
        if ((left->isRed) && ((leftLeft)->isRed))
        {
            left->right = root;
            root->left = NULL;

            left->isRed = false;
            leftLeft->isRed = false;
            return left;
        }
    }
    return root;
}

static RBTreeNode* rotateRight(RBTreeNode* root)
{
    RBTreeNode* right = root->right;
    if ((right) && (right->isRed))
    {
        right->left = root;
        root->right = NULL;
    }
    return right;
}

static RBTreeNode* flipColors(RBTreeNode* root)
{
    if ((root->left) && (root->right))
    {
        if (((root->left)->isRed) && ((root->right)->isRed))
        {
            (root->left)->isRed = false;
            (root->right)->isRed = false;
        }
    }
    return root;
}

void printInOrder(TreeMap* tree)
{
    if (!tree) {
        return;
    }
    printTreeInOrder(tree->root);
}

static void printTreeInOrder(RBTreeNode* root)
{
    if (!root) {
        return;
    }
    printTreeInOrder(root->left);
    fprintf(stderr, "%d, ", root->key);
    printTreeInOrder(root->right);
}