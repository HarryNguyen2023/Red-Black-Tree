#include <iostream>
#include "RBTree.h"

// Function to initiate the node of the Red Black Tree
template <typename T>
RBTree<T>::RBTree()
{
    root = nullptr;
    size = 0;
}

// Function to create a new node for reb black tree
template <typename T>
RBNode* RBTree<T>::newNode(T data)
{
    
}