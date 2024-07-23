#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
struct PriorityQueue {
    vector<ll> heap;

    ll parent(ll i) { return (i - 1) / 2; }
    ll left(ll i) { return (2*i + 1); }
    ll right(ll i) { return (2*i + 2); }
    
    void heapifyUp(ll i) {
        ll p = parent(i);
        if (i != 0 && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(ll i) {
        ll l = left(i);
        ll r = right(i);
        ll max = i;
        ll size = heap.size();
        if (l < size && heap[max] < heap[l]) max = l;
        if (r < size && heap[max] < heap[r]) max = r;
        if (max != i) {
            swap(heap[i], heap[max]);
            heapifyDown(max);
        }
    }

    ll GetSize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void push(ll x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (isEmpty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    ll top() {
        if (!isEmpty()) return heap.front();
    }
};

int main() {
    ll n, k; cin >> n >> k;
    PriorityQueue pq;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        pq.push(x);
    }
    ll sum = 0;
    while (k--) {
        sum += pq.top();
        ll repl = pq.top() - 1;
        pq.pop();
        pq.push(repl);
    }
    cout << sum;
    return 0;
}