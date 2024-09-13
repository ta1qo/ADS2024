#include<iostream>
#include<algorithm>
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p) {
    Node* cur = head;
    if (p == 0) {
        node->next = head;
        head = node;
    } else {
        for (int i = 0; i < p - 1; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}
 
Node* remove(Node* head, int p) {
    Node* cur = head;
    if (p == 0) {
        head = head->next;
    } else {
        for (int i = 0; i < p - 1; i++) {
            cur = cur->next;
        }
        Node* tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2) {
    Node *cur1 = head, *cur2 = head;
    Node *prev1 = nullptr, *prev2 = nullptr;
    int cnt = 0;
    if (p1 == 0 && p2 == 0) {
        return head;
    }
    while (cnt < p1) {
        prev1 = cur1;
        cur1 = cur1->next;
        cnt++;
    }
    if (p1 == 0) {
        head = head->next;
        cur2 = head;
    }
    if (p1 != 0) {
        prev1->next = cur1->next;
    }
    cnt = 0;
    while (cnt < p2) {
        prev2 = cur2;
        cur2 = cur2->next;
        cnt++;
    }
    if (p2 != 0) {
        prev2->next = cur1;
        cur1->next = cur2;
    } else {
        cur1->next = cur2;
    }
    if (p2 == 0) {
        head = cur1;
        return head;
    }
    return head;
}
 
Node* reverse(Node* head){
    Node *prev = nullptr, *next = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    Node* cur = head;
    if (cur == nullptr) {
        cout << -1 << "\n";
        return;
    }
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int x){
    Node *cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    while (x--) {
        cur->next = head;
        head = head->next;
        cur = cur->next;
        cur->next = nullptr;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    Node *cur = head;
    int cnt = 1;
    while (cur->next != nullptr) {
        cur = cur->next;
        cnt++;
    }
    cur->next = head;
    x = cnt - x;
    while (x--) {
        cur = cur->next;
    }
    head = cur->next;
    cur->next = nullptr;
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true) {
        int command; cin >> command;
        if (command == 0){
            break;
        } else if(command == 1) {
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2) {
            int p; cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x; cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}
