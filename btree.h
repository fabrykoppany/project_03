#ifndef PROJECT_03_BTREE_H
#define PROJECT_03_BTREE_H

#include "runtime_type.h"

typedef struct TreeNode {
    RUNTIME_TYPE value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(RUNTIME_TYPE value);
TreeNode *insertNode(TreeNode *root, RUNTIME_TYPE value, int *comparisons, int *arithmetic);
TreeNode *searchTree(TreeNode *root, RUNTIME_TYPE value, int *comparisons, int *arithmetic);
TreeNode *minValueNode(TreeNode *root, int *comparisons);
TreeNode *maxValueNode(TreeNode *root, int *comparisons);
TreeNode *deleteNode(TreeNode *root, RUNTIME_TYPE value, int *comparisons);
int countTree(TreeNode *root, int *comparisons, int *arithmetics);
void printPreorder(TreeNode *root);
void printInorder(TreeNode *root);
void printPostorder(TreeNode *root);
int height(TreeNode *tree);
TreeNode * readBtreeFromInputFile(TreeNode *tree, const char *file_name, int *comparisons, int *arithmetic);
void freeTree(TreeNode *tree);

RUNTIME_TYPE getWorstCaseBtree(TreeNode *tree, int height);
RUNTIME_TYPE getBestCaseBtree(TreeNode *tree);
RUNTIME_TYPE getAvgCaseBtree(TreeNode *tree, int height);

#include <stdlib.h>
#include <stdio.h>

#endif //PROJECT_03_BTREE_H
