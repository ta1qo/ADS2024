#include <iostream>
using namespace std;

bool check(char a, char b) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') return a < b;
        else return true;
    }
    else if (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u') return false;
    else return a < b;
}

int partition(char arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left-1);
    for (int j = left; j <= right-1; j++) {
        if (check(arr[j], arr[pivot])) {
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
    int n; cin >> n;
    string s; cin  >> s;
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    return 0;
}