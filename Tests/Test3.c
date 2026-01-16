// This Test for Add an array
#include "..\src\binarytreeofobada.h"
#include <stdio.h>
int main(){
    printf("Program start\n");
    // make tree
    BinaryTree tree;

    // init with macro function(constractor)
    BST_init(tree, double);

    // Now i can add a lot of element very fast
    double array[] = {50,20,70,60,80,120,-30,40,10,-10,0,100,110};
    BST_Add_Arr(tree, array);
    
    // Printing binary tree
    printf("Print start\n");
    Print_Binarytree_InOrder(&tree);
    
    // Free binary tree (deconstractor)
    printf("free start\n");
    Free_Binarytree(&tree);
    
}