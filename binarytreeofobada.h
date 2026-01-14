#ifndef BINARY_TREE_OF_OBADA_H
#define BINARY_TREE_OF_OBADA_H
// struct of node
#include <stdlib.h>
typedef int (*CompareFn)(void*, void*);
typedef struct Node {
	
	struct Node* left;// SMALLER
    struct Node* right;// BIGGER
	void* data;
	
}Node;
// struct of list
typedef struct BinaryTree{
	Node* head;
	size_t size_Type;
	CompareFn compare_function;
}BinaryTree;
//Prototips of functions
void New_Binarytree(BinaryTree* tree,size_t ST, CompareFn cf);
void Free_Binarytree(BinaryTree* tree);
void Add_element_Binarytree(BinaryTree* tree, void* Ndata);
void Print_Binarytree_InOrder_double(BinaryTree* tree);
int Compare_int(void* a, void* b);
int Compare_double(void* a, void* b); 
int Compare_float(void* a, void* b);
#define BST_init(tree, type) New_Binarytree(&tree, sizeof(type), (Compare_##type))
#endif