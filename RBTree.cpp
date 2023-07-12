#include <iostream>
#include "RBTree.h"

// Function to initiate the node of the Red Black Tree
template <typename T>
RBTree<T>::RBTree()
{
    size = 0;
    NIL = new Node<T>();
    NIL->color = 'B';
    NIL->left = nullptr;
    NIL->right = nullptr;
    root = NIL;
}

// Function to create a new node for reb black tree
template <typename T>
Node<T>* RBTree<T>::newNode(T data)
{
    Node<T>* newnode = new Node<T>();
    newnode->color = 'R';
    newnode->data = data;
    newnode->left = NIL;
    newnode->right = NIL;
    newnode->parent = nullptr;
    return newnode;
}

// Function to inorder traverse the tree
template <typename T>
void RBTree<T>::inTraverse(Node<T>* node)
{
    if(node == nullptr)
        return;
    inTraverse(node->left);
    std::cout<<node->data<<" ";
    inTraverse(node->right);
}

// Function to generally inorder traverse the tree
template <typename T>
void RBTree<T>::inTraverse()
{
    if(root == nullptr)
        return;
    std::cout<<"Element in the tree inorder: ";
    inTraverse(root);
    std::cout<<std::endl;
}

// Function to preorder traverse the tree
template <typename T>
void RBTree<T>::preTraverse(Node<T>* node)
{
    if(node == nullptr)
        return;
    std::cout<<node->data<<" ";
    preTraverse(node->left);
    preTraverse(node->right);
}

// Function to generally inorder traverse the tree
template <typename T>
void RBTree<T>::preTraverse()
{
    if(root == nullptr)
        return;
    std::cout<<"Element in the tree preorder: ";
    preTraverse(root);
    std::cout<<std::endl;
}

// Function to saerch for a node in the tree
template <typename T>
bool RBTree<T>::search(Node<T>* node, T data)
{
    if(node == NIL)
        return false;
    else if(data < node->data)
        return search(node->left, data);
    else if(data > node->data)
        return search(node->right, data);
    else
        return true;
}

// Function to generally search for a key in the tree
template <typename T>
bool RBTree<T>::search(T data)
{
    if(root == NIL)
        return false;
    return search(root, data);
}

// Function to print the shape of the tree
template <typename T>
void RBTree<T>::print2D(Node<T>* node, int COUNT, int space)
{
    // Base case
    if (node == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process right child first
    print2D(node->right, COUNT, space);
    // Print current node after space
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << node->data<<"-"<<node->color<< "\n";
    // Process left child
    print2D(node->left, COUNT, space);
}

// Function to generally print the shape of the tree
template <typename T>
void RBTree<T>::printTree()
{
    print2D(root, 10, 0);
}

// Function to perform left rotation in red black tree
template <typename T>
Node<T>* RBTree<T>::leftRotate(Node<T>* x)
{
    Node<T>* y = x->right;
    // Rotate left
    x->right = y->left;
    if(y->left != NIL)
        y->left->parent = x;

    y->left = x;
    // Swap the parent
    y->parent = x->parent;
    if(x->parent == nullptr)
        root = y;
    else if(x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    x->parent = y;
}

// Function to perform right rotation in red black tree
template <typename T>
Node<T>* RBTree<T>::rightRotate(Node<T>* y)
{
    Node<T>* x = y->left;
    y->left = x->right;
    if(x->right != NIL)
        x->right->parent = y;
    
    x->right = y;
    x->parent = y->parent;
    if(y->parent == nullptr)
        root = x;
    else if(y->parent->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;
    y->parent = x;
}

// Function to insert a new node into the Red Black Tree
template <typename T>
void RBTree<T>::insertFix(Node<T>* node)
{
    // Check if the parent of the new inserted key is Red
    while(node->parent->color == 'R')
    {
        if(node->parent == node->parent->parent->left)
        {
            Node<T>* uncle = node->parent->parent->right;
            if(uncle->color == 'R')
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else 
            {
                if(node == node->parent->right)
                {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                rightRotate(node->parent->parent);
            }
        }
        else
        {
            Node<T>* uncle = node->parent->parent->left;
            if(uncle->color == 'R')
            {
                node->parent->color = 'B';
                uncle->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else 
            {
                if(node == node->parent->left)
                {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                leftRotate(node->parent->parent);
            } 
        }
        // Loop until we reach the root node
        if(node == root)
            break;
    }
    root->color = 'B';
    return;
}

// Function to generally insert a new node into the Red Black tree
template <typename T>
void RBTree<T>::insert(T data)
{
    Node<T>* newnode = newNode(data);
    Node<T>* temp = root;
    Node<T>* parent = nullptr;
    // Traverse to the leaf node for insertion of the new key
    while (temp != NIL)
    {
        parent = temp;
        if(data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    // Now we reach the leaf and insert the new key
    if(parent == nullptr)
        root = newnode;
    else if(data < parent->data)
        parent->left = newnode;    
    else
        parent->right = newnode;
    newnode->parent = parent;

    // Case root node
    if(newnode->parent == nullptr)
    {
        newnode->color = 'B';
        return;
    }

    if(newnode->parent->parent == nullptr)
        return;
    // Call the function to fix if the color property is violated
    insertFix(newnode);
}

// Function to merge the parent with the child key in deletion
template <typename T>
void RBTree<T>::merge(Node<T>* parent, Node<T>* child)
{
    // Swap the parent with the child
    if(parent->parent == nullptr)
        root = child;
    else if(parent == parent->parent->left)
        parent->parent->left = child;
    else
        parent->parent->right = child;
    child->parent = parent->parent;
}

// Function to get the inorder predecessor of the node
template <typename T>
Node<T>* RBTree<T>::inSucc(Node<T>* node)
{
    while(node->left != NIL)
        node = node->left;
    return node;
}

// Function to fix the color property violation during deletion of the red black tree
template <typename T>
void RBTree<T>::delFix(Node<T>* node)
{
    while(node != root && node->color == 'B')
    {
        if(node == node->parent->left)
        {
            Node<T>* sibling = node->parent->right;
            if(sibling->color == 'R')
            {
                sibling->color = 'B';
                node->parent->color = 'R';
                leftRotate(node->parent);
                sibling = node->parent->right;
            }
            if(sibling->left->color == 'B' && sibling->right->color == 'B')
            {
                sibling->color = 'R';
                node = node->parent;
            }
            else
            {
                if(sibling->right->color == 'B')
                {
                    sibling->left->color = 'B';
                    sibling->color = 'R';
                    rightRotate(sibling);
                    sibling = node->parent->right;
                }
                sibling->color = node->parent->color;
                node->parent->color = 'B';
                sibling->right->color = 'B';
                leftRotate(node->parent);
                node = root;
            }
        }
        else
        {
            Node<T>* sibling = node->parent->left;
            if(sibling->color == 'R')
            {
                sibling->color = 'B';
                node->parent->color = 'R';
                rightRotate(node->parent);
                sibling = node->parent->left;
            }
            if(sibling->left->color == 'B' && sibling->right->color == 'B')
            {
                sibling->color = 'R';
                node = node->parent;
            }
            else
            {
                if(sibling->left->color == 'B')
                {
                    sibling->right->color = 'B';
                    sibling->color = 'R';
                    leftRotate(sibling);
                    sibling = node->parent->left;
                }
                sibling->color = node->parent->color;
                node->parent->color = 'B';
                sibling->right->color = 'B';
                rightRotate(node->parent);
                node = root;
            }
        }
        // Color the root
        node->color = 'B';
    }
}

// Function to delete a key in the red black tree
template <typename T>
void RBTree<T>::delNode(Node<T>* node, T data)
{
    Node<T>* delnode = NIL;
    Node<T>* pred;
    Node<T>* succ;
    // Traverse to the node to be deleted
    while(node != NIL)
    {
        if(data == node->data)
        {
            delnode = node;
            break;
        }
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }
    // Chech if the key is in the tree
    if(delnode == NIL)
    {
        std::cout<<"Key is not in the tree"<<std::endl;
        return;
    }

    // Save the original color of the delnode
    succ = delnode;
    char ori_col = succ->color;
    if(delnode->left == NIL)
    {
        pred = delnode->right;
        merge(delnode, delnode->right);
    }
    else if(delnode->right == NIL)
    {
        pred = delnode->left;
        merge(delnode, delnode->left);
    }
    else
    {
        succ = inSucc(node->right);
        ori_col = succ->color;
        if(succ->parent == delnode)
            pred->parent = succ;
        else
        {
            merge(succ, succ->right);
            succ->right = delnode->right;
            succ->right->parent = succ;
        }
        merge(delnode, succ);
        succ->left = delnode->left;
        succ->left->parent = succ;
        succ->color = delnode->color;
    }
    delete delnode;
    if(ori_col == 'B')
        delFix(pred);
}

// Function to generally delete a key in the red black tree
template <typename T>
void RBTree<T>::delNode(T data)
{
    // Check if the root is empty
    if(root == NIL)
        return;
    // Traverse to the delete node
    delNode(root, data); 
}

int main()
{
    // Initiate the Red Black Tree
    RBTree<int> rbtree;
    // Insert a few node to the tree
    int random[] = {5, 7, 8, 9, 3, 1, 13, 10, 25, 37, 46, 106, 67, 55, 92, 84};
    for(int i = 0; i < sizeof(random)/sizeof(int); ++i)
        rbtree.insert(random[i]);
    // Traverse the tree
    rbtree.inTraverse();
    // Search for a few node in the tree
    std::cout<<"Node 5 is "<<(rbtree.search(5) ? "" : "not ")<<"in the red black tree"<<std::endl;
    std::cout<<"Node 37 is "<<(rbtree.search(37) ? "" : "not ")<<"in the red black tree"<<std::endl;
    std::cout<<"Node 230 is "<<(rbtree.search(230) ? "" : "not ")<<"in the red black tree"<<std::endl;
    // Display the shape of the key
    rbtree.printTree();
    // Delete a few node in the key
    rbtree.delNode(9);
    rbtree.delNode(106);
    rbtree.delNode(550);
    // Search for deleted node
    std::cout<<"Node 9 is "<<(rbtree.search(9) ? "" : "not ")<<"in the red black tree"<<std::endl;
    std::cout<<"Node 106 is "<<(rbtree.search(106) ? "" : "not ")<<"in the red black tree"<<std::endl;
    // Display the tree again
    rbtree.printTree();
    return 0;
}