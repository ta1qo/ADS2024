#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string val;
    Node *next;

    Node(string x) {
        this->val = x;
        this->next = NULL;
    }
};

struct LL {
    Node *head;
    Node *cur;
    int size;

    LL() {
        this->head = NULL;
        this->cur = this->head;
        this->size = 0;
    }

    LL(string val) {
        this->head = new Node(val);
        this->cur = this->head;
        this->size = 1;
    }

    void add(string val) {
        cur->next = new Node(val);
        cur = cur->next;
        size++;
    }

    void print() {
        Node *tmp = head;
        cout << size << '\n';
        while (tmp != NULL) {
            cout << tmp->val << '\n';
            tmp = tmp->next;
        }
    }
};

int LPS(string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }

    return lps[m - 1];
}

int main() {
    string s; cin >> s;
    int n; cin >> n;

    s[0] = tolower(s[0]);
    int max = -1;
    LL list;
    
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        string tmp = t;
        tmp[0] = tolower(t[0]);
        tmp = tmp + '#' + s;
        int length = LPS(tmp);
        if (max < length) {
            max = length;
            list = LL(t);
        } else if (max == length) {
            list.add(t);
        }
    }

    if (max == 0) {
        cout << 0;
        return 0;
    }

    list.print();

    return 0;
}