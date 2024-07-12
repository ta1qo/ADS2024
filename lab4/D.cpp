#include <iostream>
#include <vector>
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

    int get_height() const {
        return get_height(root);
    }

    void printLevelSum() {
        vector<int> levelSum(get_height(), 0);
        calculateLevelSum(root, 0, levelSum);
        for (int i = 0; i < get_height(); i++) {
            cout << levelSum[i] << ' ';
        }
        cout << endl;
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

    int get_height(Node* current) const {
        if (current == nullptr) return 0;
        return 1 + max(get_height(current->left), get_height(current->right));
    }

    void calculateLevelSum(Node* current, int level, vector<int>& levelSum) {
        if (current == nullptr) return;
        levelSum[level] += current->data;
        calculateLevelSum(current->left, level + 1, levelSum);
        calculateLevelSum(current->right, level + 1, levelSum);
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
    cout << bst.get_height() << endl;
    bst.printLevelSum();
    return 0;
}