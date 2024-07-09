#include <iostream>
#include <queue>
using namespace std;

template<typename T>
struct Node {
    T data;
    Node *left, *right;

    Node(T data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

template<typename T>
Node<T>* insert(Node<T>* root, T data) {
    if (root == nullptr) {
        return new Node<T>(data); 
    }
    queue<Node<T>*> q;
    q.push(root);
    while (!q.empty()) {
        Node<T>* temp = q.front();
        q.pop();
        if (temp->left == nullptr) {
            temp->left = new Node<T>(data);
            break;
        } else {
            q.push(temp->left);
        }
        if (temp->right == nullptr) {
            temp->right = new Node<T>(data);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

template<typename T>
void deleteDeepest(Node<T>* root, Node<T>* d_node) {
    queue<Node<T>*> q;
    q.push(root);
    Node<T>* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = nullptr;
            delete d_node;
            return;
        }
        if (temp->left != nullptr) {
            if (temp->left == d_node) {
                temp->left = nullptr;
                delete d_node;
                return;
            } else {
                q.push(temp->left);
            }
        }
        if (temp->right != nullptr) {
            if (temp->right == d_node) {
                temp->right = nullptr;
                delete d_node;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

template<typename T>
Node<T>* deletion(Node<T>* root, T key) {
    if (root == nullptr) 
        return nullptr;
    if (root->left == nullptr && root->right == nullptr) {
        if (root->data == key) {
            delete root;
            return nullptr;
        } else {
            return root;
        }
    }
    queue<Node<T>*> q;
    q.push(root);
    Node<T>* temp = nullptr;
    Node<T>* key_node = nullptr;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key) 
            key_node = temp;
        if (temp->left) 
            q.push(temp->left);
        if (temp->right) 
            q.push(temp->right);
    }
    if (key_node != nullptr) {
        T x = temp->data;
        key_node->data = x;
        deleteDeepest(root, temp);
    }
    return root;
}

int main() {
    Node<int>* root = new Node<int>(10);
    root = insert(root, 11);
    root = insert(root, 7);
    root = insert(root, 9);
    root = insert(root, 15);
    root = insert(root, 8);


    int key = 11;
    root = deletion(root, key);

    return 0;
}
