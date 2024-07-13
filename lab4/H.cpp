#include <iostream>
using namespace std;

template<typename T>
class BST {
public: 
    BST() : size(0), root(nullptr) {}
    ~BST() {
        clear(root);
    }

    int get_size() {
        return size;
    }

    void insert(T data) {
        root = insert(root, data);
    }

    void replace_keys() {
        T accumulator = 0;
        replace_keys(root, accumulator);
    }

    void print_tree() const {
        print_tree(root); cout << endl;
    }

private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;

        Node(T data = T(), Node* left = nullptr, Node* right = nullptr) {
            this->data = data;
            this->left = left;
            this->right = right;
        }
    };

    int size;
    Node* root;

    Node* insert(Node* current, T data) {
        if (current == nullptr) {
            size++; return new Node(data); 
        }
        if (data < current->data) current->left = insert(current->left, data);
        else if (data > current->data) current->right = insert(current->right, data);
        return current;
    }

    void replace_keys(Node* current, T& accumulator) {
        if (current == nullptr) return;
        replace_keys(current->right, accumulator);
        accumulator += current->data;
        current->data = accumulator;
        replace_keys(current->left, accumulator);
    }

    void print_tree(Node* current) const {
        if (current == nullptr) return;
        print_tree(current->right);
        cout << current->data << " ";
        print_tree(current->left);
    }

    void clear(Node* current) {
        if (current == nullptr) return;
        clear(current->left);
        clear(current->right);
        delete current;
    }
};

int main() {
    int n; cin >> n;
    BST<int> bst;
    while (n--) {
        int x; cin >> x;
        bst.insert(x);
    }
    bst.replace_keys();
    bst.print_tree();
    return 0;
}