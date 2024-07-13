#include <iostream>
#include <string>
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

    int get_multiplicity(T data) const {
        Node* current = search(root, data);
        return (current) ? current->mult : 0;
    }

    void delete_node(T data) {
        root = delete_node(root, data);
    }

private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        int mult;

        Node(T data = T(), Node* left = nullptr, Node* right = nullptr) {
            this->data = data;
            this->left = left;
            this->right = right;
            this->mult = 1;
        }
    };

    int size;
    Node* root;

    Node* insert(Node* current, T data) {
        if (current == nullptr) {
            size++; return new Node(data); 
        }
        if (data == current->data) current->mult += 1;
        else if (data < current->data) current->left = insert(current->left, data);
        else if(data > current->data) current->right = insert(current->right, data);
        return current;
    }

    Node* search(Node* current, T data) const {
        if (current == nullptr) return nullptr;
        if (current->data == data) return current;
        return (data < current->data) ? search(current->left, data) : search(current->right, data);
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
            if (current->mult > 1) {
                current->mult -= 1;
                return current;
            }
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
                current->mult = 1;
                current->left = delete_node(current->left, maxInLeft->data);
            }
        }
        return current;
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
        string s; cin >> s;
        int x; cin >> x;
        if (s == "insert") bst.insert(x);
        else if (s == "delete") bst.delete_node(x);
        else if (s == "cnt") cout << bst.get_multiplicity(x) << endl;
    }
    return 0;
}