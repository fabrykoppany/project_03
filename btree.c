#include "btree.h"

TreeNode *createNode(RUNTIME_TYPE value) {
    TreeNode *node = (TreeNode *) calloc(1, sizeof(TreeNode));

    if (node == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    node->value = value;
    return node;
}

TreeNode *insertNode(TreeNode *root, RUNTIME_TYPE value) {
    if (root == NULL) {
        root = createNode(value);
    } else {
        int valueComparison = compareTypes(root->value, value);

        if (valueComparison > 0) {
            root->left = insertNode(root->left, value);
        } else if (valueComparison < 0) {
            root->right = insertNode(root->right, value);
        }
    }

    return root;
}

TreeNode *searchTree(TreeNode *root, RUNTIME_TYPE value) {
    if (root == NULL) {
        return NULL;
    }

    int valueComparison = compareTypes(root->value, value);

    if (valueComparison == 0) {
        return root;
    } else if (valueComparison > 0) {
        return searchTree(root->left, value);
    } else {
        return searchTree(root->right, value);
    }
}

TreeNode *minValueNode(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *p = root;

    while (p->left != NULL) {
        p = p->left;
    }

    return p;
}

TreeNode *maxValueNode(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *p = root;

    while (p->right != NULL) {
        p = p->right;
    }

    return p;
}


TreeNode *deleteNode(TreeNode *root, RUNTIME_TYPE value) {
    if (root == NULL) {
        return NULL;
    }

    TreeNode *result = root;
    int valueComparison = compareTypes(root->value, value);

    if (valueComparison > 0) {
        root->left = deleteNode(root->left, value);
    } else if (valueComparison < 0) {
        root->right = deleteNode(root->right, value);
    } else if (root->left == NULL) {
        result = root->right;
        free(root);
    } else if (root->right == NULL) {
        result = root->left;
        free(root);
    } else {
        TreeNode *targetNode = maxValueNode(root->left);
        root->value = targetNode->value;
        root->left = deleteNode(root->left, root->value);
    }

    return result;
}

int countTree(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countTree(root->left) + countTree(root->right);
}

void printPreorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printRuntimeType(root->value);
    printf(" ");
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printRuntimeType(root->value);
    printf(" ");
    printInorder(root->right);
}

void printPostorder(TreeNode *root) {
    if (root == NULL) {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    printRuntimeType(root->value);
    printf(" ");
}