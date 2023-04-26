//
// Created by akaan on 24.04.2023.
//

#ifndef GIMMEV2_LIB_BST_H
#define GIMMEV2_LIB_BST_H
#include "bst_utils.h"

typedef struct node Node;
typedef struct bst Tree;

struct node{
    void* data;
    Node* left, * right;
};
struct bst{
    Node* root;
};

Node* newNode(void* data);
Tree* newBST();
void insertNode(Tree*, void*, funCompare);
void printInorder(Tree*, FILE*, funPrint);
void clear(Tree* bst);
#endif //GIMMEV2_LIB_BST_H
