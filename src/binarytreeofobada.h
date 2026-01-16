// HEADER FILE

// Prototips of private functions

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

// Including Libararies
#include <stdio.h> 	// printf()
#include <string.h> // memcpy()
#include <stdlib.h> // malloc(), free()

// Pointer Functions
typedef int (*CompareFn)(void*, void*);
typedef void (*PrintFn)(void*);

// Structures

// Struct of Node
typedef struct Node {
	
	struct Node* left;// SMALLER
    struct Node* right;// BIGGER
	void* data;
	
}Node;

// Struct of Binary Search Tree
typedef struct BinaryTree{
	Node* head;
	size_t size_Type;
	CompareFn compare_function;
	PrintFn print_function;
}BinaryTree;


// Prototips of functions
void New_Binarytree(BinaryTree* tree,size_t ST, CompareFn cf, PrintFn pf); 		//initialization
void Free_Binarytree(BinaryTree* tree); 										//destruction
void Add_element_Binarytree(BinaryTree* tree, void* Ndata); 					//element insertion
void Print_Binarytree_InOrder(BinaryTree* tree); 								//in-order traversal print functions
void Add_array_Binarytree(BinaryTree* tree, size_t size_of_arr,void* array);	//array-based insertion function  

// Macro Functions

// Constractor function simplification macro function.
#define BST_init(tree, type) New_Binarytree(&tree, sizeof(type), (Compare_##type), (Print_##type))
// Add an array function simplification macro function.
#define BST_Add_Arr(tree, arr) Add_array_Binarytree(&tree, sizeof(arr), arr)
// Compare two numbers macro function for Compare functions.
#define COMPARE(a,b) ((a > b) - (b > a))

#endif