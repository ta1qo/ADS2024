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
        if (i != 0 && heap[i] < heap[p]) {
            swap(heap[i], heap[p]);
            heapifyUp(p);
        }
    }

    void heapifyDown(ll i) {
        ll l = left(i);
        ll r = right(i);
        ll min = i;
        ll size = heap.size();
        if (l < size && heap[min] > heap[l]) min = l;
        if (r < size && heap[min] > heap[r]) min = r;
        if (min != i) {
            swap(heap[i], heap[min]);
            heapifyDown(min);
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
    ll q, k; cin >> q >> k;
    PriorityQueue pq;
    ll sum = 0;
    while (q--) {
        string s; cin >> s;
        if (s == "print") cout << sum << endl;
        else if (s == "insert") {
            ll x; cin >> x;
            if (pq.GetSize() < k) {
                pq.push(x); sum += x;  
            }
            else if (pq.top() < x) {
                sum += x - pq.top();
                pq.pop();
                pq.push(x);
            }
        }
    }
    
    return 0;
}