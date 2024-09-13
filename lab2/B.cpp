#include<iostream>
using  namespace std;

template<typename T>
class List {
public:
    List() : head(nullptr), tail(nullptr) {}

    void push_back(T data) {
        Node *current = new Node(data);
        if (head == nullptr) {
            head = tail = current;
        } else {
            tail->pNext = current;
            tail = current;
        }
    }

    void pop_front() {
        Node *temp = head;
        head = head->pNext;
        delete temp;
    }

    void shiftedBy(int k) {
        while (k--) {
            push_back(head->data);
            pop_front();
        }
    }

    void print() {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->pNext;
        }
        cout << endl;
    } 

private:
    class Node {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    Node *head;
    Node *tail;
};

int main() {
    int n, k;
    cin >> n >> k;

    List<string> lst;
    for (int i = 0; i < n; i++) {
        string data;
        cin >> data;
        lst.push_back(data);
    }

    lst.shiftedBy(k);

    lst.print();

    return 0;
}