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

    void push_front(T data) {
        head = new Node(data, head);
        Size++;
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

    void insert(T data, int index) {
        if (index == 0) {   
            push_front(data);
        } else {
            Node *previous = this->head;
            for (int i = 0; i < index - 1; i++) {
                previous = previous->pNext;
            }   
            Node *newNode = new Node(data, previous->pNext);
            previous->pNext = newNode;
        }
        
        Size++;
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

    int newdata, position;
    cin >> newdata >> position;
    lst.insert(newdata, position);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << ' ';
    }

    return 0;
}