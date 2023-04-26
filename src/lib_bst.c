//
// Created by akaan on 24.04.2023.
//

#include "../inc/lib_bst.h"
#include <stdlib.h>
#define mem_alloc(type, size) (type*)calloc(size, sizeof(type));
#define null NULL
Node* newNode(void* data){
    Node* node = mem_alloc(Node, 1);
    if(node==null) return null;
    node->data = data;
    node->left = node->right = null;
    return node;
}
Tree* newBST(){
    Tree* bst = mem_alloc(Tree, 1);
    bst->root = null;
    return bst;
}
static Node* insert_node(Node* node, void* data, funCompare cmp){
    if(node == null) return newNode(data);
    if(cmp(data,node->data)>=0) node->right = insert_node(node->right, data, cmp);
    else node->left = insert_node(node->left, data, cmp);
    return node;
}
void insertNode(Tree* bst, void* data, funCompare cmp){
    if(bst == null) return;
    bst->root = insert_node(bst->root, data, cmp);
}

static void print_inorder(Node* node, FILE* file, funPrint p){
    if(node==null) return;
    print_inorder(node->left, file, p);
    p(node->data, file);
    print_inorder(node->right, file, p);
}

void printInorder(Tree* bst, FILE* file, funPrint p){
    if(bst == null) return;
    print_inorder(bst->root, file, p);
}

static void clear_postorder(Node* node){
    if(node == null) return;
    clear_postorder(node->left);
    clear_postorder(node->right);
    if(node->data!=null){
        free(node->data);
        node->data = null;
    }
    free(node);
}

void clear(Tree* bst){
    if(bst == null) return;
    clear_postorder(bst->root);
    free(bst);
}