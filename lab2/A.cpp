#include<iostream>
using namespace std;

template<typename t>
class list {
public: 
    list() : size(0), head(nullptr) {}
    ~list() {
        clear();
    }

    int getsize() const {
        return size;
    }

    void push_back(t data) {
        if (head == nullptr) {
            head = new node(data, head);
        } else {
            node *current = this->head;
            while (current->pnext != nullptr) {
                current = current->pnext;
            }
            current->pnext = new node(data);
        }

        size++;
    }

    int nearestTo(t k) {
        int difference = INT_MAX;
        int offset = 0;
        node *current = this->head;

        for (int i = 0; i < getsize(); i++) {
            int value = abs(current->data - k);
            if (difference > value) {
                difference = value;
                offset = i;
            }
            current = current->pnext;
        }

        return offset;
    }

    void clear() {
        while (size) {
            node *temp = head;
            head = head->pnext;
            delete temp;

            size--;
        }
    }

    t &operator[](const int index) {
        int counter = 0;
        node *current = this->head;
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pnext;
            counter++;
        }
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

    int size;
    node *head;
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

    int offset = lst.nearestTo(k);
    cout << offset;

    return 0;