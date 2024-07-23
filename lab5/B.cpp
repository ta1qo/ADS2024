#include <iostream>
#include <vector>
using namespace std;

struct PriorityQueue {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    
    void heapifyUp(int i) {
        int p = parent(i);
        if (i != 0 && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int max = i;
        int size = heap.size();
        if (l < size && heap[max] < heap[l]) max = l;
        if (r < size && heap[max] < heap[r]) max = r;
        if (max != i) {
            swap(heap[i], heap[max]);
            heapifyDown(max);
        }
    }

    int GetSize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (isEmpty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (!isEmpty()) return heap.front();
    }
};

int main() {
    int n; cin >> n;
    PriorityQueue pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    while(pq.GetSize() > 1) {
        int y = pq.top(); pq.pop();
        int x = pq.top(); pq.pop();
        if (x != y) {
            pq.push(y - x);
        }
    }
    cout << (pq.GetSize() > 0 ? pq.top() : 0); 

    return 0;
}