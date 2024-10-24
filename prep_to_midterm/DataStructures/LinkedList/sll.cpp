#include<iostream>             
using  namespace std;
// A singly linked list is a linear data structure which contains a sequence of nodes, where each node stores data and pointer(reference) to the next node.
// The first and last nodes are called head and tail, the next pointer of tail is set to null.
// Time Complexity of operations:
// Access (by index): O(n), Search for an Element: O(n)
// Insert at Beginning: O(1), Insert at End: O(n), Insert at Middle: O(n)
// Delete from Beginning: O(1), Delete from End: O(n)
// Implementation of a singly linked list
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

    void pop_front() {
        if (head == nullptr) return;

        Node *temp = head;
        head = head->pNext;
        delete temp;

        Size--;
    }

    void pop_back() {
        if (Size == 0) return;

        removeAt(Size - 1);
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

            Size++;
        }
    }

    void removeAt(int index) {
        if (index == 0) {   
            pop_front();
        } else {
            Node *previous = this->head;
            for (int i = 0; i < index - 1; i++) {
                previous = previous->pNext;
            }   
            Node *toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            delete toDelete;
            
            Size--;
        }
    }

    void clear() {
        while (Size) {
            pop_front();
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
    List<int> lst;
    
    lst.push_front(5);
    lst.insert(8, 1);
    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << ' ';
    }

    return 0;
}