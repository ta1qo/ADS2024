#include<iostream>
#include<string>
using namespace std;

template<typename T>
class List {
public:
    List() : Size(0), head(nullptr), tail(nullptr) {}

    ~List() { 
        clear(); 
    }

    int GetSize() const {
        return Size;
    }

    void push_back(T data) {
        Node *current = new Node(data);
        if (head == nullptr) {
            head = tail = current;
        } else {
            tail->pNext = current;
            tail = current;
        }
        Size++;
    }

    void remove_duplicates() {
        Node *current = this->head;
        while (current->pNext != nullptr) {
            if (current->data == current->pNext->data) {
                Node *toDelete = current->pNext;
                current->pNext = toDelete->pNext;
                delete toDelete;
                Size--;
            } else {
                current = current->pNext;
            }
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
    Node *tail;
};


int main() {
    int n;
    cin >> n;

    List<string> lst;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        lst.push_back(name);
    }

    lst.remove_duplicates();

    cout << "All in all: " << lst.GetSize() << "\nStudents:\n";
    for (int i = lst.GetSize() - 1; i >= 0; i--) {
        cout << lst[i] << endl; 
    }

    return 0;
}