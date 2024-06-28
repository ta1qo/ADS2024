#include<iostream>
using  namespace std;

template<typename T>
class List {
public:
    List() : Size(0), head(nullptr) {}

    ~List() { 
        clear(); 
    }

    int GetSize() const {
        return Size;
    }

    void push_back(T data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node *current = this->head;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node(data);
        }

        Size++;
    }

    void pop_front() {
        Node *temp = head;
        head = head->pNext;
        delete temp;

        Size--;
    }

    void shiftedBy(int k) {
        while (k--) {
            push_back(head->data);
            pop_front();
        }
    }

    void clear() {
        while (Size) {
            Node *temp = head;
            head = head->pNext;
            delete temp;

            Size--;
        }
    }

    T &operator[](const int index) {
        int counter = 0;
        Node *current = this->head;
        while (current != nullptr) {
            if (counter == index) {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
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

    int Size;
    Node *head;
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

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << ' ';
    }

    return 0;
}