#include<iostream>
#include<deque>
using namespace std;

void drunkard_card_game(deque<int> d1, deque<int> d2) {
    int moves = 0;
    const int limit = 1000000;

    while (!d1.empty() && !d2.empty() && limit > moves) {
        int card1 = d1.front();
        int card2 = d2.front();
        d1.pop_front();
        d2.pop_front();
        

        if ((card1 == 0 && card2 == 9) || (card1 > card2 && !(card1 == 9 && card2 == 0))) {
            d1.push_back(card1);
            d1.push_back(card2);
        } else {
            d2.push_back(card1);
            d2.push_back(card2);
        }
        moves++;
    }

    if (d1.empty()) {
        cout << "Nursik " << moves;
    } else if (d2.empty()) {
        cout << "Boris " << moves;
    } else {
        cout << "blin nichya";
    }
}

int main() {
    deque<int> d1, d2;
    int t;
    for (int i = 0; i < 5; i++) {
        cin >> t;
        d1.push_back(t);
    }
    for (int i = 0; i < 5; i++) {
        cin >> t;
        d2.push_back(t);
    }

    drunkard_card_game(d1, d2);

    return 0;
}
