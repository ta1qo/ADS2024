#include <iostream>

using namespace std;

struct node {
    int val;
    node * next;
    node(int x) {
        val = x;
        next = NULL;
    }
};

struct queue{
    private:
        node * head;
        node * tail;
        int len;
    
    public:
        queue() {
            head = tail = NULL;
            len = 0;
        };
        void add (int x) {
            node * n = new node(x);
            len++;
            if (head == NULL) {
                head = tail = n;
            } else {
                tail->next = n;
                tail = n;
            }
        }
        void print(){
            node * cur = head;
            while(cur != NULL){
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
};

int main(){

    queue q;
    int a[] = {1, 20, 10, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);

    for(int i = 0; i < n; ++i){
        q.add(a[i]);
    }
    q.print();
    return 0;
}
