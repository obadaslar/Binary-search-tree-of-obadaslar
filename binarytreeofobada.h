// Compare functions
int Compare_int(void* a, void* b);
int Compare_double(void* a, void* b); 
int Compare_float(void* a, void* b);
//Print functions
void Print_int(void* a);
void Print_double(void* a); 
void Print_float(void* a);
#ifndef BINARY_TREE_OF_OBADA_H
#define BINARY_TREE_OF_OBADA_H
// struct of node
#include <stdlib.h>
typedef int (*CompareFn)(void*, void*);
typedef void (*PrintFn)(void*);
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
	PrintFn print_function;
}BinaryTree;
//Prototips of functions
void New_Binarytree(BinaryTree* tree,size_t ST, CompareFn cf, PrintFn pf);
void Free_Binarytree(BinaryTree* tree);
void Add_element_Binarytree(BinaryTree* tree, void* Ndata);
void Print_Binarytree_InOrder(BinaryTree* tree);
void Add_array_Binarytree(BinaryTree* tree, size_t size_of_arr,void* array);

#define BST_init(tree, type) New_Binarytree(&tree, sizeof(type), (Compare_##type), (Print_##type))
#define BST_Add_Arr(tree, arr) Add_array_Binarytree(&tree, sizeof(arr), arr)
#endif