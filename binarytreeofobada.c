#include "binarytreeofobada.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Print Functions
void Print_int(void* a) {
    printf("%d, ", *(int*)a);
}
void Print_float(void* a) {
    printf("%f, ", *(float*)a);
}
void Print_double(void* a) {
    printf("%lf, ", *(double*)a);
}

// Compare Functions

// compare macro funtion
#define COMPARE(a, b) (((a) > (b)) - ((a) < (b)))
// Compare functions
#
int Compare_int(void* a, void* b) {
    return COMPARE(*(int*)a, *(int*)b);
}
int Compare_float(void* a, void* b) {
    return COMPARE(*(float*)a, *(float*)b);
}
int Compare_double(void* a, void* b){
    return COMPARE(*(double*)a, *(double*)b);
}

// Constractor

void New_Binarytree(BinaryTree* tree, size_t ST, CompareFn cf, PrintFn pf) {  
    tree->head = NULL;
    tree->size_Type = ST;
    tree->compare_function = cf;
    tree->print_function = pf;
}

// Deconstractor

static void Free_Node_BST(Node* node) {
	if (node == NULL) return;
    Free_Node_BST(node->left);// Free left side
    Free_Node_BST(node->right);
    free(node->data);
    free(node);
    node = NULL;
    return;
}
void Free_Binarytree(BinaryTree* tree) {
    if (!tree) return;
    Free_Node_BST(tree->head);
    tree->head = NULL;
}

// Adding element functions

static void Add_element_Node_BST(BinaryTree* tree, Node** node, void* Ndata){
    if(*node == NULL) {
        *node = malloc(sizeof(Node));
        if (!(*node)){return;}
        (*node)->data = malloc(tree->size_Type);
        memcpy( (*node)->data, Ndata, tree->size_Type);

        (*node)->left = NULL;
        (*node)->right = NULL;
        return;}
    int r = tree->compare_function(Ndata, (*node)->data);
    if (r > 0) {Add_element_Node_BST(tree, &(*node)->right, Ndata);return;} 
    else if (r < 0) {Add_element_Node_BST(tree, &(*node)->left, Ndata);return;} 
    return;
}
void Add_element_Binarytree(BinaryTree* tree,void* Ndata) {
    if (!(tree->head)){
        tree->head = malloc(sizeof(Node));
        if (!(tree->head)){return;}
        tree->head->data = malloc(tree->size_Type);
        memcpy( tree->head->data, Ndata, tree->size_Type);
        tree->head->left = NULL;
        tree->head->right = NULL;
        return;
    }
    int r = tree->compare_function(Ndata, tree->head->data);
    if (r > 0) {Add_element_Node_BST(tree, &tree->head->right, Ndata);return;}
    else if (r < 0) {Add_element_Node_BST(tree, &tree->head->left, Ndata);return;}
    return;
}

// Printing tree functions

static void Print_Node_BST_InOrder(Node* node,BinaryTree* tree){
    if(!node) return;
    Print_Node_BST_InOrder(node->left, tree);
    tree->print_function(node->data);
    Print_Node_BST_InOrder(node->right, tree);
    return;
}
void Print_Binarytree_InOrder(BinaryTree* tree){
    Print_Node_BST_InOrder(tree->head,tree);
}

// Adding an array

void Add_array_Binarytree(BinaryTree* tree, size_t size_of_arr,void* array){
    for(size_t i = 0; i < size_of_arr/tree->size_Type; i++){
        char* base = (char*)array;
        char* Ndata = (base+(i * tree->size_Type));
        Add_element_Binarytree(tree,Ndata);
    }
}