#include <iostream>
#include <vector>
using namespace std;
// A priority queue is a type of queue that arranges elements based on their priority values. 
// Elements with higher priority values are typically retrieved or removed before elements with lower priority values. 
// Each element has a priority value associated with it. When we add an item, it is inserted in a position based on its priority value.
// Time Complexity(by using heaps): insert() = O(log n), remove() = O(log n), peek() = O(1); 
// Implementation of a priority queue using a max-heap:
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
    return 0;
}