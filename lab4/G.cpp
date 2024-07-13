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

    int get_max_distance() const {
        return get_diameter(root) + 1;
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
        if (current == nullptr) {size++; return new Node(data);}
        if (data < current->data) current->left = insert(current->left, data);
        else if (data > current->data) current->right = insert(current->right, data);
        return current;
    }

    int get_height(Node* current, int& diameter) const {
        if (current == nullptr) return 0;
        int left_height = get_height(current->left, diameter);
        int right_height = get_height(current->right, diameter);
        diameter = max(diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }

    int get_diameter(Node* current) const {
        int diameter = 0;
        get_height(current, diameter);
        return diameter;
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

    cout << bst.get_max_distance();
    return 0;
}