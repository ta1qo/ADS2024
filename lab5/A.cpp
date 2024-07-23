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
        if (i != 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int min = i;
        int size = heap.size();
        if (l < size && heap[min] > heap[l]) min = l;
        if (r < size && heap[min] > heap[r]) min = r;
        if (min != i) {
            swap(heap[i], heap[min]);
            heapifyDown(min);
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
    int cost = 0;
    while (pq.GetSize() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int merged = first + second;

        
        cost += merged;
        pq.push(merged);
    }
    cout << cost;
    return 0;
}