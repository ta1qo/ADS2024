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

    int count_of_mini_triangles() {
        return count_of_mini_triangles(root);
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

    int count_of_mini_triangles(Node *current) {
        if (current == nullptr) return 0;
        int cnt = 0;
        if (current->left != nullptr && current->right != nullptr) cnt = 1;
        return cnt + count_of_mini_triangles(current->left) + count_of_mini_triangles(current->right);
    }

    void clear(Node* current) {
        if (current == nullptr) return;
        clear(current->left);
        clear(current->right);
        delete current;
    }
};

int main() {
    int n;
    cin >> n;
    BST<int> bst;
    while (n--) {
        int x; cin >> x;
        bst.insert(x);
    }
    cout << bst.count_of_mini_triangles();
    return 0;
}