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

    void delete_every_second() {
        if (head == nullptr || head->pNext == nullptr) { 
            return;
        }
        
        Node *current = this->head;
        while (current != nullptr && current->pNext != nullptr) {
            Node *temp = current->pNext;
            current->pNext = (current->pNext)->pNext;
            delete temp;

            Size--;

            current = current->pNext;
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
    int n;
    cin >> n;

    List<int> lst;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        lst.push_back(data);
    }

    lst.delete_every_second();

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << ' ';
    }

    return 0;
}