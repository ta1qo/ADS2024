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

    void insert(T parent, T child, int direction) {
        if (root == nullptr) {
            root = new Node(parent); size++;
        }
        return insert(root, parent, child, direction);
    }

    bool search(T data) const {
        return search(root, data) != nullptr;
    }

    int get_height() const {
        return get_height(root);
    }

    int get_width() const {
        return get_max_width(root);
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

    void insert(Node* current, T parent, T child, int direction) {
        if (current == nullptr) return;
        current = search(current, parent);
        Node* temp = new Node(child);
        if (direction == 0) {current->left = temp; size++;}
        else if (direction == 1) {current->right = temp; size;} 
    }

    Node* search(Node* current, T data) const {
        if (current == nullptr) return nullptr;
        if (current->data == data) return current;
        Node* leftSearch = search(current->left, data);
        if (leftSearch != nullptr) return leftSearch;
        return search(current->right, data);
    }

    int get_height(Node* current) const {
        if (current == nullptr) return 0;
        return 1 + max(get_height(current->left), get_height(current->right));
    }

    int calculate_width(Node* current, int level) const {
        if (current == nullptr) return 0;
        if (level == 1) return 1;
        return calculate_width(current->left, level - 1) + calculate_width(current->right, level - 1);
    }

    int get_max_width(Node* current) const {
        int max_width = 0, h = get_height(current);
        for (int i = 1; i <= h; i++) {
            int width = calculate_width(current, i);
            if (width > max_width) 
                max_width = width;
        }
        return max_width;
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
    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        bst.insert(x, y, z);
    }
    cout << bst.get_width();
    return 0;
}