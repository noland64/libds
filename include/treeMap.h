#ifndef TREE_MAP_H
#define TREE_MAP_H

typedef struct TreeMap TreeMap;

TreeMap* treeMapCreate(void);
int treeMapDestroy(TreeMap* tree);
int treeMapInsert(TreeMap* tree, int key, int val);
int treeMapRemove(TreeMap* tree, int key);
int treeMapPop(TreeMap* tree, int key);
int treeMapGet(TreeMap* tree, int key);
int treeMapSize(TreeMap* tree);
void printInOrder(TreeMap* tree);
#endif