#include<iostream>
using  namespace std;
// implementation of a doubly linked list
template<typename T>
class DList {
public:
    DList() : Size(0), head(nullptr), tail(nullptr) {}

    ~DList() { 
        clear(); 
    }   

    int GetSize() const {
        return Size;    
    }

    void push_front(T data) {
        Node *newNode = new Node(data, nullptr, head);

        if (head) {
            head->pPrev = newNode;
            newNode->pNext = head;
            head = newNode;
        } else {
            head = tail = newNode;
        }

        Size++;
    }

    void push_back(T data) {
        Node *newNode = new Node(data, tail, nullptr); 

        if (tail) {
            tail->pNext = newNode;
            newNode->pPrev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }

        Size++;
    }

    void pop_front() {
        if (head == nullptr) return;

        Node *temp = head;
        head = head->pNext;
        
        if (head != nullptr) 
            head->pPrev = nullptr;
        else 
            tail = nullptr;

        delete temp;
        Size--;
    }

    void pop_back() {
        if (tail == nullptr) return;

        Node *temp = tail;
        tail = tail->pPrev;
        
        if (tail != nullptr) 
            tail->pNext = nullptr;
        else 
            head = nullptr;

        delete temp;
        Size--;
    }

    void insert(T data, const int index) {
        if (index == 0) {   
            push_front(data);
        } else if (Size == index) {
            push_back(data);
        } else {
            Node *ptr;
            if (Size / 2 >= index) {
                ptr = this->head;
                for (int i = 0; i < index - 1; i++) {
                    ptr = ptr->pNext;
                }
            } else {
                ptr = this->tail;
                for (int i = Size - index; i > 0; i--) {
                    ptr = ptr->pPrev;
                }
            }
            Node *newNode = new Node(data, ptr, ptr->pNext);
            (ptr->pNext)->pPrev = newNode;
            ptr->pNext = newNode;

            Size++;
        }
    }

    void removeAt(int index) {
        if (index == 0) {   
            pop_front();
        } else if (index == Size - 1) {
            pop_back();
        } else {
            Node *ptr;
            if (Size / 2 >= index) {
                ptr = this->head;
                for (int i = 0; i < index - 1; i++) {
                    ptr = ptr->pNext;
                }
            } else {
                ptr = this->tail;
                for (int i = Size - index; i > 0; i--) {
                    ptr = ptr->pPrev;
                }
            }
            Node *toDelete = ptr->pNext;
            ptr->pNext = toDelete->pNext;

            if (toDelete->pNext != nullptr) {
                toDelete->pNext->pPrev = ptr;
            }
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
        Node *pPrev, *pNext;
        T data;

        Node(T data = T(), Node *pPrev = nullptr, Node *pNext = nullptr) {
            this->data = data;
            this->pPrev = pPrev;
            this->pNext = pNext;
        }
    };

    int Size;
    Node *head, *tail;
};


int main() {
    int n;
    cin >> n;
    DList<int> dlst;
    
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        dlst.push_back(data);
    }

    dlst.removeAt(4);

    for (int i = 0; i < dlst.GetSize(); i++) {
        cout << dlst[i] << ' ';
    } 
    
    return 0;
}