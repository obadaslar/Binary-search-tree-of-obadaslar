#ifndef BINARY_TREE_OF_OBADA_H
#define BINARY_TREE_OF_OBADA_H
// struct of node
typedef struct Node {
	double data;//not generic(currently)
	struct Node* left;// SMALLER
    struct Node* right;// BIGGER
}Node;
// struct of list
typedef struct BinaryTree{
	Node* head;
}BinaryTree;
//Prototips of functions
void New_Binarytree(BinaryTree* tree);
void Free_Binarytree(BinaryTree* tree);
void Add_element_Binarytree(BinaryTree* tree,double Ndata/*simdilik*/);
void Print_Binarytree_InOrder(BinaryTree* tree);
#endif