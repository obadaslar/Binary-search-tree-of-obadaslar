// This Test for Add an array
#include "..\src\binarytreeofobada.h"
#include <stdio.h>
int main(){
    printf("Program start\n");
    // Make a Binary search tree
    BinaryTree tree;

    // init with macro function (constractor).
    BST_init(tree, double);

    // Now i can add a lot of element very fast.
    double array[] = {50,20,70,60,80,120,-30,40,10,-10,0,100,110};
    BST_Add_Arr(tree, array);
    
    // Printing a Binary search tree with simple API.
    printf("Print start\n");
    Print_Binarytree_InOrder(&tree);
    printf("\n");
    
    // Free binary tree with c function (deconstractor).
    Free_Binarytree(&tree);
    
}