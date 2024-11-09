#include <iostream>
#include <map>
using namespace std;

int mod = 1e9 + 7;
int p = 31;

struct Node {
    string val;
    Node *next;

    Node (string x) {
        this->val = x;
        this->next = NULL;
    }
};

struct LL {
    Node *head;
    Node *current;

    void add(string x) {
        this->current->next = new Node(x);
        this->current = current->next;
    }

    void print() {
        Node *tmp = head;
        while (tmp != NULL) {
            cout << tmp->val << '\n';
            tmp = tmp->next;
        }
    }

    LL () {
        this->head = NULL;
        this->current = this->head;
    }

    LL (string x) {
        this->head = new Node(x);
        this->current = this->head;
    }
};

int get_hash(string s) {
    int h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * p + (s[i] - 'a' + 1);
    }
    return h;
}

int rk(string s1, string t) {
    int n = s1.length(), m = t.length();
    int hs1 = get_hash(s1.substr(0, m));
    int ht = get_hash(t);
    int pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }
    int cnt = 0;
    for (int i = 0; i + m <= n; i++) {
        if (hs1 == ht)
            cnt++;
        if (i + m < n)
            hs1 = (hs1 - pm * (s1[i] - 'a' + 1)) * p + (s1[i + m] - 'a' + 1);
    }
    return cnt;
}

int main() {
    while(true) {
        int n; cin >> n;
        if (n == 0)
            break;

        string lang[n];
        map <int, LL> res;
        int max_length = 0;
        for (int i = 0; i < n; i++) {
            cin >> lang[i];
        }
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            int current = rk(s, lang[i]);
            if (res[current].head == NULL)
                res[current] = LL(lang[i]);
            else
                res[current].add(lang[i]);
            if (max_length < current) {
                max_length = current;
            }
        }
        cout << max_length << '\n';
        res[max_length].print();
    }

    return 0;
}