#include "binarytreeofobada.h"
#include <stdio.h>
#include <stdlib.h>
void New_Binarytree(BinaryTree* tree) {  
    tree->head = NULL;
}


static void Free_Node_BST(Node* node) {
	if (node == NULL) return;
    Free_Node_BST(node->left);// Free left side
    Free_Node_BST(node->right);
    free(node);
    return;
}
void Free_Binarytree(BinaryTree* tree) {
    if (!tree) return;
    Free_Node_BST(tree->head);
    tree->head = NULL;
}
static void Add_element_Node_BST(Node** node, double Ndata){
    if(*node == NULL) {
        *node = malloc(sizeof(Node));
        if (!(*node)){return;}
        (*node)->data = Ndata;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;}
    if ((*node)->data < Ndata) {Add_element_Node_BST(&(*node)->right, Ndata);return;} 
    if ((*node)->data > Ndata) {Add_element_Node_BST(&(*node)->left, Ndata);return;} 
    return;
}

void Add_element_Binarytree(BinaryTree* tree,double Ndata/*simdilik*/) {
    if (!(tree->head)){
        tree->head = malloc(sizeof(Node));
        if (!(tree->head)){return;}
        tree->head->data = Ndata;
        tree->head->left = NULL;
        tree->head->right = NULL;
        return;
    }
    if (tree->head->data < Ndata) {Add_element_Node_BST(&tree->head->right,  Ndata);return;}
    if (tree->head->data > Ndata) {Add_element_Node_BST(&tree->head->left, Ndata);return;}
    return;
}

static void Print_Node_BST_InOrder(Node* node){
    if(!node) return;
    Print_Node_BST_InOrder(node->left);
    printf("%f, ", node->data);
    Print_Node_BST_InOrder(node->right);
    return;
}
void Print_Binarytree_InOrder(BinaryTree* tree){
    Print_Node_BST_InOrder(tree->head);
}

//void Print_Binarytree_TREE(){
//}