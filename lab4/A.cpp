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

    bool isPeak(const string& path) {
        Node* current = find_node(root, path);
        return (current != nullptr && current->left == nullptr && current->right == nullptr);
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

    Node* find_node(Node* current, const string& path) {
        for (char p : path) {
            if (current == nullptr) return nullptr;
            if (p == 'L') current = current->left;
            else if (p == 'R') current = current->right;
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
    int n, m;
    cin >> n >> m;
    BST<int> bst;
    while (n--) {
        int x; cin >> x;
        bst.insert(x);
    }
    while (m--) {
        string path; cin >> path;
        cout << (bst.isPeak(path) ? "YES" : "NO") << endl;
    }
    return 0;
}