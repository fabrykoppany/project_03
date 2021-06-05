//#include <dvec.h>
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

TreeNode *insertNode(TreeNode *root, RUNTIME_TYPE value, int *comparisons, int *arithmetic) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        root = createNode(value);
    } else {
        (*comparisons) = (*comparisons) + 1;

        int valueComparison = compareTypes(root->value, value);

        (*comparisons) = (*comparisons) + 1;

        if (valueComparison > 0) {
            root->left = insertNode(root->left, value, comparisons, arithmetic);
        } else if (valueComparison < 0) {
            root->right = insertNode(root->right, value, comparisons, arithmetic);
        }
    }

    return root;
}

TreeNode *searchTree(TreeNode *root, RUNTIME_TYPE value, int *comparisons, int *arithmetic) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        return NULL;
    }

    (*comparisons) = (*comparisons) + 1;

    int valueComparison = compareTypes(root->value, value);

    (*comparisons) = (*comparisons) + 1;

    if (valueComparison == 0) {
        return root;
    } else if (valueComparison > 0) {
        return searchTree(root->left, value, comparisons, arithmetic);
    } else {
        return searchTree(root->right, value, comparisons, arithmetic);
    }
}

TreeNode *minValueNode(TreeNode *root, int *comparisons) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        return NULL;
    }

    TreeNode *p = root;

    while (p->left != NULL) {
        (*comparisons) = (*comparisons) + 1;
        p = p->left;
    }

    (*comparisons) = (*comparisons) + 1;

    return p;
}

TreeNode *maxValueNode(TreeNode *root, int *comparisons) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        return NULL;
    }

    TreeNode *p = root;

    while (p->right != NULL) {
        (*comparisons) = (*comparisons) + 1;
        p = p->right;
    }

    (*comparisons) = (*comparisons) + 1;

    return p;
}


TreeNode *deleteNode(TreeNode *root, RUNTIME_TYPE value, int *comparisons) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        return NULL;
    }

    TreeNode *result = root;

    (*comparisons) = (*comparisons) + 1;

    int valueComparison = compareTypes(root->value, value);

    (*comparisons) = (*comparisons) + 1;

    if (valueComparison > 0) {
        root->left = deleteNode(root->left, value, comparisons);
    } else if (valueComparison < 0) {
        (*comparisons) = (*comparisons) + 1;
        root->right = deleteNode(root->right, value, comparisons);
    } else if (root->left == NULL) {
        (*comparisons) = (*comparisons) + 1;
        result = root->right;
        freeRuntimeType(root->value);
        free(root);
    } else if (root->right == NULL) {
        (*comparisons) = (*comparisons) + 1;
        result = root->left;
        freeRuntimeType(root->value);
        free(root);
    } else {
        TreeNode *targetNode = maxValueNode(root->left, comparisons);
        root->value = targetNode->value;
        root->left = deleteNode(root->left, root->value, comparisons);
    }

    return result;
}

int countTree(TreeNode *root, int *comparisons, int *arithmetics) {
    (*comparisons) = (*comparisons) + 1;

    if (root == NULL) {
        return 0;
    }

    (*arithmetics) = (*arithmetics) + 2;

    return 1 + countTree(root->left, comparisons, arithmetics) + countTree(root->right, arithmetics, arithmetics);
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

int height(TreeNode *tree){
    if (tree == NULL){
        return 0;
    }

    int leftHt = height(tree->left);
    int rightHt = height(tree->right);

    if (leftHt > rightHt){
        return leftHt + 1;
    }
    else {
        return rightHt + 1;
    }
}

TreeNode * readBtreeFromInputFile(TreeNode *tree, const char *file_name, int *comparisons, int *arithmetic){
    FILE *input_file = fopen(file_name, "r");

    (*comparisons) = (*comparisons) + 1;

    if (input_file == NULL){
        printf("Error opening %s", file_name);
        exit(-1);
    }

    int n;

    fscanf(input_file, "%i", &n);

    for (int i = 0; i < n; (*arithmetic) = (*arithmetic) + 1, (*comparisons) = (*comparisons) + 1, ++i){
        tree = insertNode(tree, readRuntimeType(input_file), comparisons, arithmetic);
    }

    return tree;
}

TreeNode *destroyBtree(TreeNode *tree){
    int comp = 0;

    while (tree != NULL){
        RUNTIME_TYPE mini = minValueNode(tree, &comp)->value;
        tree = deleteNode(tree, mini, &comp);
        if (tree == NULL){
            break;
        }
    }

    return tree;
}

RUNTIME_TYPE getWorstCaseBtree(TreeNode *tree, int height) {
    if (tree == NULL){
        return NO_ELEMENT;
    }

    if (height == 1){
        return tree->value;
    }
    else {
        if (height > 1){
            getWorstCaseBtree(tree->left, height - 1);
            getWorstCaseBtree(tree->right, height - 1);
        }
    }
}

RUNTIME_TYPE getBestCaseBtree(TreeNode *tree){
    if (tree == NULL){
        return NO_ELEMENT;
    }

    return tree->value;
}

RUNTIME_TYPE getAvgCaseBtree(TreeNode *tree, int height) {
    if (tree == NULL){
        return NO_ELEMENT;
    }

    if (height == 1){
        return tree->value;
    }
    else {
        if (height > 1){
            getAvgCaseBtree(tree->left, height - 1);
            getAvgCaseBtree(tree->right, height - 1);
        }
    }
}