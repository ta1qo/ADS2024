#include <iostream>
using namespace std;

bool check(char a, char b) {
    return a < b;
}

int partition(char arr[], int left, int right) {
    char pivot = arr[right];
    int i = (left-1);
    for (int j = left; j <= right-1; j++) {
        if (check(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return (i+1);
}

void quickSort(char arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index-1);
    quickSort(arr, index+1, right);
}

int main() {
    string s; cin  >> s;
    char arr[s.size()];
    for (int i = 0; i < s.size(); i++) {
        arr[i] = s[i];
    }
    quickSort(arr, 0, s.size() - 1);
    for (int i = 0; i < s.size(); i++) {
        cout << arr[i];
    }
    return 0;
}