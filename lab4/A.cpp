#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;

    Node (int x) {
        this->val = x;
        this->left = this->right = NULL;
    }
};

struct Bst {
    Node *root;

    Bst () {
        this->root = NULL;
    }

    Node *add (Node *current, int x) {
        if (current == NULL) {
            current = new Node(x);
        }
        else if (current->val > x) {
            if (current->left == NULL)
                current->left = add(current->left, x);
            else
                add(current->left, x);
        }
        else {
            if (current->right == NULL)
                current->right = add(current->right, x);
            else
                add(current->right, x);
        }
        return current;
    }

    Node *search (Node *current, int x) {
        if (current == NULL)
            return NULL;
        if (current->val == x)
            return current;
        else if (current->val > x)
            return search(current->left, x);
        else if (current->val < x)
            return search(current->right, x);
    }

    void print (Node * current){
        if(current != NULL){
            print(current->left);
            cout << current->val << " ";
            print(current->right);
        }
    }
};

int main() {
    Bst *B = new Bst();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (B->root == NULL)
            B->root = B->add(B->root, x);
        else
            B->add(B->root, x);
    }
    while(m--) {
        string s; cin >> s;
        Node *current = B->root;
        for (int i = 0; i < s.length(); i++) {
            if (current == NULL) {
                break;
            }
            if (s[i] == 'L') {
                current = current->left;
            }
            if (s[i] == 'R') {
                current = current->right;
            }
        }
        if (current != NULL)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}