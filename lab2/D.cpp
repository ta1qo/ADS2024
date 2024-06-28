#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
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

    vector<int> find_modes() {
        unordered_map<int, int> frequency;
        Node *current = this->head;

        while (current != nullptr) {
            frequency[current->data]++;
            current = current->pNext;
        }

        int max_frequency = 0;
        unordered_map<int, int>::iterator it;
        for (it = frequency.begin(); it != frequency.end(); it++) {
            if (it->second > max_frequency) {
                max_frequency = it->second;
            }
        }

        vector<int> mode_s;
        for (it = frequency.begin(); it != frequency.end(); it++) {
            if (it->second == max_frequency) {
                mode_s.push_back(it->first);
            }
        }

        sort(mode_s.begin(),mode_s.end(), greater<int>());
        
        return mode_s;
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

    vector<int> mode_s = lst.find_modes();
    for (int i : mode_s) {
        cout << i << ' ';
    }

    return 0;
}