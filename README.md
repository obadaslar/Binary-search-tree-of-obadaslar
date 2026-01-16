# Binary-search-tree-of-obadaslar
Binary search tree with C language. In this project I do Binary search tree that generic and simple structure with simple API design.

## What does do?
This project is for data structure type is BST with generic functions.
Binary Search Tree (BST) is tree graph all elements are have just two sides named left and right. And has rules that the bigger number is in right side and smaller number is in left side.
## What does it do?

This project implements a **generic Binary Search Tree (BST)** data structure in C.

A Binary Search Tree is a tree-based data structure where each node has at most two children, called **left** and **right**.
The tree follows the rule that values smaller than the current node are stored in the left subtree, while larger values are stored in the right subtree.

## What does it include and how does it works?

### Project structure

    BINARY_TREE\
├────── *Tests\\*
| └────── Test3.c
├────── *src\\*
|   ├─── binarytreeofobada.c
    |   └─── binarytreeofobada.h
├─── LICENSE
├─── README.md
└─── .gitinore

### What does have in Source (src\\)?

#### `binarytreeofobada.c`

This file contains the core implementation of the generic Binary Search Tree.

- Required library includes  
  (`stdio.h`, `stdlib.h`, `string.h`, `binarytreeofobada.h`)

- Type-specific **print** and **compare** functions  
  (for `int`, `float` and `double`)

- Tree initialization (constructor-like) function  
  (`New_Binarytree()`)

- Tree destruction functions  
  - `Free_Binarytree()`  
  - `Free_Node_BST()` *(internal / private)*

- Element insertion functions  
  - `Add_element_Binarytree()`  
  - `Add_element_Node_BST()` *(internal / private)*

- In-order traversal print functions  
  (prints elements from smallest to largest)  
  - `Print_Binarytree_InOrder()`  
  - `Print_Node_BST_InOrder()` *(internal / private)*

- Array-based insertion function  
  - `Add_array_Binarytree_InOrder()`  
  *(basic but relatively complex implementation)*

#### `binarytreeofobada.h`

This header file defines a generic Binary Search Tree (BST) implementation in C.
The tree is designed to store arbitrary data types using void* pointers and relies on user-provided compare and print functions to operate on the stored data.

##### Main Features:

- Generic data storage using void*

- Custom comparison and print functions via function pointers

- Dynamic memory management

- In-order traversal support

- Array-based bulk insertion

- Core Structures

###### Node
Represents a single node in the binary search tree.
Each node stores:

A pointer to the left child (smaller values)

A pointer to the right child (larger values)

A generic data pointer (`void*`)

###### BinaryTree
Represents the binary search tree itself and stores:

A pointer to the root node

The size of the stored data type

A comparison function pointer

A print function pointer

##### Function Pointer Types

`CompareFn`
Used to compare two elements stored in the tree.

`PrintFn`
Used to print a single element stored in the tree.

##### Public API Overview

`New_Binarytree`
Initializes a binary search tree with user-defined comparison and print functions.

`Free_Binarytree`
Frees all memory associated with the tree.

`Add_element_Binarytree`
Inserts a single element into the tree.

`Add_array_Binarytree`
Inserts multiple elements from an array.

`Print_Binarytree_InOrder`
Prints the tree contents using in-order traversal.

##### Macros

- BST_init
Simplifies tree initialization for a specific data type.

- BST_Add_Arr
Simplifies inserting an array into the tree.

- Compare
A helper macro for implementing comparison functions.