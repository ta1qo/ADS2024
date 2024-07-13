#include <iostream>
using namespace std;
// binary search tree implementation
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

    bool search(T data) const {
        return search(root, data) != nullptr;
    }

    T get_min() const {
        if (root == nullptr) return 0;
        Node* minNode = get_min(root);
        return minNode->data;
    }

    T get_max() const {
        if (root == nullptr) return 0;
        Node* maxNode = get_max(root);
        return maxNode->data;
    }

    void delete_node(T data) {
        root = delete_node(root, data);
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

    Node* search(Node* current, T data) const {
        if (current == nullptr) return nullptr;
        if (current->data == data) return current;
        return (data < current->data) ? search(current->left, data) : search(current->right, data);
    }

    Node* get_min(Node* current) const {
        if (current == nullptr) return nullptr;
        if (current->left == nullptr) return current;
        return get_min(current->left);
    }

    Node* get_max(Node* current) const {
        if (current == nullptr) return nullptr;
        if (current->right == nullptr) return current;
        return get_max(current->right);
    }

    Node* delete_node(Node* current, T data) {
        if (current == nullptr) return nullptr;
        else if (data < current->data) current->left = delete_node(current->left, data);
        else if (data > current->data) current->right = delete_node(current->right, data);
        else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current; size--;
                return temp;
            } else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current; size--;
                return temp;
            } else {
                Node* maxInLeft = get_max(current->left);
                current->data = maxInLeft->data;
                current->left = delete_node(current->left, maxInLeft->data);
            }
        }
        return current;
    }

    void print_tree(Node* current) const {
        if (current == nullptr) return;
        print_tree(current->left);
        cout << current->data << " ";
        print_tree(current->right);
    }

    void clear(Node* current) {
        if (current == nullptr) return;
        clear(current->left);
        clear(current->right);
        delete current;
    }
};

int main() {
    return 0;
}