#ifndef PROJECT_03_BTREE_H
#define PROJECT_03_BTREE_H

#include "runtime_type.h"

typedef struct TreeNode {
    RUNTIME_TYPE value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(RUNTIME_TYPE value);
TreeNode *insertNode(TreeNode *root, RUNTIME_TYPE value);
TreeNode *searchTree(TreeNode *root, RUNTIME_TYPE value);
TreeNode *minValueNode(TreeNode *root);
TreeNode *maxValueNode(TreeNode *root);
TreeNode *deleteNode(TreeNode *root, RUNTIME_TYPE value);
int countTree(TreeNode *root);
void printPreorder(TreeNode *root);
void printInorder(TreeNode *root);
void printPostorder(TreeNode *root);

#include <stdlib.h>
#include <stdio.h>

#endif //PROJECT_03_BTREE_H
