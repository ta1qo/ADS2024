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

int NthSuperPrime(int N) {
    int firstPrime = prime_by_index(N);
    int secondPrime = prime_by_index(firstPrime);
    return secondPrime;
}

int main() {
    int n;
    cin >> n;
    int ans = NthSuperPrime(n);
    cout << ans;
    
    return 0;
}

