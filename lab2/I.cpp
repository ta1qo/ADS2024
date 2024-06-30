#include<iostream>
#include<string> 
using  namespace std;

template<typename T>
class DList {
public:
    DList() : Size(0), head(nullptr), tail(nullptr) {}

    ~DList() { 
        clear(); 
    }   

    bool empty() {
        return Size == 0;
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

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
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
    DList<string> dlst;

    string s;

    while (cin >> s) {
        if (s == "add_front") {
   			string t;
   			cin >> t;
   			dlst.push_front(t);
   			cout << "ok" << endl;
   		}
   		if (s == "add_back") {
   			string t;
   			cin >> t;
   			dlst.push_back(t);
   			cout << "ok" << endl;
   		}
   		if (s == "erase_front") {
   			if (dlst.empty()) {
   				cout << "error" << endl;
   			} else {
   				cout << dlst.front() << endl;
   				dlst.pop_front();
   			}
   		}
   		if (s == "erase_back") {
   			if(dlst.empty()){
   				cout << "error" << endl;
   			} else {
   				cout << dlst.back() << endl;
   				dlst.pop_back();
   			}
   		}
   		if (s == "front") {
   			if (dlst.empty()) {
   				cout << "error" << endl;
   			} else {
   				cout << dlst.front() << endl;
   			}
   		}
   		if (s == "back") {
   			if (dlst.empty()) {
   				cout << "error" << endl;
   			} else {
   				cout << dlst.back() << endl;
   			}
   		}
   		if (s == "clear") {
   			dlst.clear();
   			cout << "ok" << endl;
   		}
   		if (s == "exit") {
   			cout << "goodbye" << endl;
   			break;
   		}
    }
    
    return 0;
}