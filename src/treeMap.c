#include <stdio.h>
#include "treeMap.h"
#include "node.h"
#include "errors.h"

struct TreeMap
{
    RBTreeNode* root;
    int size;
};

TreeMap* treeMapCreate(void)
{
    return NULL;
}

int treeMapDestroy(TreeMap* tree)
{
    return SUCCESS;
}

int treeMapInsert(TreeMap* tree, int key, int val)
{
    return SUCCESS;
}

int treeMapRemove(TreeMap* tree, int key)
{
    return SUCCESS;
}

int treeMapPop(TreeMap* tree, int key)
{
    return 0;
}

int treeMapGet(TreeMap* tree, int key)
{
    return 0;
}

int treeMapSize(TreeMap* tree)
{
    return 0;
}