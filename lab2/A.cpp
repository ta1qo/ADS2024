#include<iostream>
using namespace std;

template<typename t>
class list {
public: 
    list() : head(nullptr), tail(nullptr) {}

    void push_back(t data) {
        node *current = new node(data, head);
        if (head == nullptr) {
            head = tail = current;
        } else {
            tail->pnext = current;
            tail = current;
        }
    }

    int nearestTo(t k, int n) {
        int difference = 99999;
        int offset = 0;
        node *current = this->head;

        for (int i = 0; i < n; i++) {
            int value = abs(current->data - k);
            if (difference > value) {
                difference = value;
                offset = i;
            }
            current = current->pnext;
        }

        return offset;
    }

private:
    class node {
    public:
        node *pnext;
        t data;

        node(t data = t(), node *pnext = nullptr) {
            this->data = data;
            this->pnext = pnext;
        }
    };

    node *head;
    node *tail;
};

int main() {
    int n;
    cin >> n;

    list<int> lst;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        lst.push_back(data);
    }

    int k;
    cin >> k;

    int offset = lst.nearestTo(k, n);
    cout << offset;

    return 0;
}