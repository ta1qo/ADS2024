#include<iostream>
#include<string>
#include<queue>
using namespace std;

string decide_the_leader(int n, queue<int> K, queue<int> S) {
    int kfirst, sfirst;

    while (!K.empty() && !S.empty()) {
        kfirst = K.front();
        sfirst = S.front();
        K.pop();
        S.pop();
        if (kfirst > sfirst) {
            S.push(sfirst + n);
        } else {
            K.push(kfirst + n);     
        }                           
    }                               

    return K.empty() ? "SAKAYANAGI" : "KATSURAGI";
}

int main() {
    int n; 
    cin >> n;

    string word;
    cin >> word;
    
    queue<int> K, S;
    for (int i = 0; i < n; i++) {
        if (word[i] == 'K') {
            K.push(i);
        } else {
            S.push(i);
        }
    }

    cout << decide_the_leader(n, K, S);

    return 0;
}