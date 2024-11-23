#include <iostream>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node *prev;
    Node *div;
    Node *add;

    Node(int a) {
        this->val = a;
        this->prev = NULL;
        this->div = NULL;
        this->add = NULL;
    }
};

struct Graph {
    Node *head;
    int depth;

    Node *push_div(int a, Node *cur) {
        Node *tmp = new Node(a);
        cur->div = tmp;
        tmp->prev = cur;
        return tmp;
    }

    Node *push_add(int a, Node *cur) {
        Node *tmp = new Node(a);
        cur->add = tmp;
        tmp->prev = cur;
        return tmp;
    }

    void print(Node *cur) {
        stack <int> tmp;
        while (cur->prev != NULL) {
            tmp.push(cur->val);
            cur = cur->prev;
            depth++;
        }
        cout << depth << '\n';
        while (depth--) {
            cout << tmp.top() << ' ';
            tmp.pop();
        }
    }

    Graph(int a) {
        this->head = new Node(a);
        this->depth = 0;
    }
};

void bfs(int a, int b) {
    unordered_set <int> visited;
    queue <Node*> q;
    Graph g = Graph(a);
    Node *n = new Node(a);
    q.push(n);
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();

        if (cur->val == b) {
            g.print(cur);
            return;
        }
        
        visited.insert(cur->val);
        
        if (cur->val < b && visited.find(cur->val * 2) == visited.end()) {
            n = g.push_div(cur->val * 2, cur);
            q.push(n);
        }

        if (cur->val - 1 >= 0 && visited.find(cur->val - 1) == visited.end()) {
            n = g.push_add(cur->val - 1, cur);
            q.push(n);
        }
    }
}

int main() {
    int a, b; cin >> a >> b;
    bfs(a, b);
}