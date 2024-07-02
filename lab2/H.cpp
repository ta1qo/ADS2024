#include<iostream>
using  namespace std;

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

    void replace(int p1, int p2) {
        if (p1 >= Size || p2 >= Size) return;

        Node *ptr1 = this->head;
        Node *ptr2 = this->head;

        if (Size / 2 >= p1) {
            ptr1 = this->head;
            for (int i = 0; i < p1; i++) {
                ptr1 = ptr1->pNext;
            }
        } else {
            ptr1 = this->tail;
            for (int i = Size - 1; i > p1; i--) {
                ptr1 = ptr1->pPrev;
            }
        }

        if (Size / 2 >= p2) {
            ptr2 = this->head;
            for (int i = 0; i < p2; i++) {
                ptr2 = ptr2->pNext;
            }
        } else {
            ptr2 = this->tail;
            for (int i = Size - 1; i > p2; i--) {
                ptr2 = ptr2->pPrev;
            }
        }

        T temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
    }

    void print() {
        if (Size == 0) {
            cout << "-1";
            return;
        }

        Node *current = this->head;
        while (current != nullptr) {
            cout << current->data << ' ';
            current = current->pNext;
        }
        cout << endl;
    }

    void reverse() {    // 12345 => 54321
        Node *current = this->head;
        Node *temp = nullptr;

        while (current != nullptr) {
            temp = current->pPrev;
            current->pPrev = current->pNext;
            current->pNext = temp;
            current = current->pPrev;
        }

        if (temp != nullptr) {
            head = temp->pPrev;
        }
    }

    // void cyclic_left(int x) {    // 12345 => 51234
    //     if (head == nullptr || head == tail) return; 
        
    //     while (x--) {
    //         Node *first = this->head;
    //         head = head->pNext;
    //         head->pPrev = nullptr;

    //         tail->pNext = first;
    //         first->pPrev = tail;
    //         first->pNext = nullptr;
    //         tail = first;
    //     }
    // }

    void cyclic_left(int x) {
        if (head == nullptr || head == tail || x == 0) return; 
        
        x %= Size;
        if (x == 0) return;
        
        Node *new_head = this->head;
        for (int i = 0; i < x; ++i) {
            new_head = new_head->pNext;
        }
        
        Node *new_tail = new_head->pPrev;
        new_tail->pNext = nullptr;
        new_head->pPrev = nullptr;
        tail->pNext = head;
        head->pPrev = tail;
        head = new_head;
        tail = new_tail;
    }

    // void cyclic_right(int x) {   // 12345 => 23451
    //     if (head == nullptr || head == tail) return;
        
    //     while (x--) {
    //         Node *last = this->tail;
    //         tail = tail->pPrev;
    //         tail->pNext = nullptr;

    //         last->pNext = head;
    //         head->pPrev = last;
    //         last->pPrev = nullptr;
    //         head = last;
    //     }
    // }

    void cyclic_right(int x) {
        if (head == nullptr || head == tail || x == 0) return;

        x %= Size;
        if (x == 0) return;
        
        Node *new_tail = this->tail;
        for (int i = 0; i < x; ++i) {
            new_tail = new_tail->pPrev;
        }

        Node *new_head = new_tail->pNext;
        new_tail->pNext = nullptr;
        new_head->pPrev = nullptr;
        tail->pNext = head;
        head->pPrev = tail;
        head = new_head;
        tail = new_tail;
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
    DList<int> dlst;
    
    while (true) {
        int command; 
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p; cin >> x >> p;
            dlst.insert(x, p);
        } else if (command == 2) {
            int p; cin >> p;
            dlst.removeAt(p);
        } else if (command == 3) {
            dlst.print();
        } else if (command == 4) {
            int p1, p2; cin >> p1 >> p2;
            dlst.replace(p1, p2);
        } else if (command == 5) {
            dlst.reverse();
        } else if (command == 6) {
            int x; cin >> x;
            dlst.cyclic_left(x);
        } else if (command == 7) {
            int x; cin >> x;
            dlst.cyclic_right(x);
        }   
    }
    
    return 0;
}