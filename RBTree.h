// Define the class of Red Black Tree node
template <class T>
class RBNode{
    private:
    T data;
    char color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
};

// Class the define the Red Black Tree
template <class T>
class RBTree
{
    private:
    RBNode* root;
    long long size;

    void printTree(RBNode* node, int space);
    RBNode* insert(RBNode* node, T data);
    RBNode* newNode(T data);

    public:
    RBTree();
    void printTree();
    void preTraverse();
    void inTraverse();
    void insert(T data);
};