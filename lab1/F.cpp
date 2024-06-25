#include<iostream>
using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for(int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int prime_by_index(int index) {
    int cnt = 0;
    for (int i = 2;; i++) {
        if (isPrime(i)) {
            cnt++;
            if (cnt == index) {
                return i; 
            }
        }
    
    }
}

int main() {
    int n;
    cin >> n;
    cout << prime_by_index(n);
    
    return 0;
}