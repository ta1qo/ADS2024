#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> d;
    char enter;
    int digit, sum = 0;
    while (cin >> enter) {
        if (enter == '+') {
            cin >> digit;
            d.push_front(digit); 
        } else if (enter == '-') {
            cin >> digit;
            d.push_back(digit);
        } else if (enter == '*') {
            if (d.empty()) {
                cout << "error\n";
            } else {
                sum = d.front() + d.back();
                cout << sum << endl;
                d.pop_front();
                if (!d.empty()) {
                    d.pop_back();
                }
            }
        } else if (enter == '!'){
            break;
        }
    }

    return 0;
}