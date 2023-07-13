// Define the struct of user information
typedef struct Infor
{
    std::string name;
    std::string pass;
    int grade;

    public:
    // Function to overwrite the operator equal == for structure use
    bool operator==(const Infor& other)
    {
        return name == other.name && pass == other.pass && grade == other.grade;
    }

    // Function to overwrite the operator > for structure use
    bool operator>(const Infor& other)
    {
        return name > other.name;
    }

    // Function to overwrite the operator < for structure use
    bool operator<(const Infor& other)
    {
        return name < other.name;
    }
}Infor;

// Define the class of Red Black Tree node
template <class T>
class Node
{
    public:
    T data;
    char color;
    Node* left;
    Node* right;
    Node* parent;
};

// Class the define the Red Black Tree
template <class T>
class RBTree
{
    private:
    Node<T>* root;
    Node<T>* NIL;
    long long size;

    void print2D(Node<T>* node,int COUNT, int space);
    void insertFix(Node<T>* node);
    Node<T>* newNode(T data);
    void preTraverse(Node<T>* node);
    void inTraverse(Node<T>* node);
    bool search(Node<T>* node, T data);
    Node<T>* leftRotate(Node<T>* x);
    Node<T>* rightRotate(Node<T>* y);
    void delFix(Node<T>* node);
    void delNode(Node<T>* node, T data);
    void merge(Node<T>* parent, Node<T>* child);
    Node<T>* inSucc(Node<T>* node);

    public:
    RBTree();
    void printTree();
    void preTraverse();
    void inTraverse();
    void insert(T data);
    bool search(T data);
    void delNode(T data);
};