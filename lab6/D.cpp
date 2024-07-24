#include <iostream>
#include <string>
using namespace std;

bool check(int a[], int b[]) {
    if (a[2] == b[2]) {
        if (a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];    
    }
    return a[2] < b[2];
}

int partition(int arr[][3], int left, int right) {
    int pivot = right;
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

void quickSort(int arr[][3], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index-1);
    quickSort(arr, index+1, right);
}

int main() {
    int n; cin >> n;
    int dates[n][3];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int day = stoi(s.substr(0, 2));
        int month = stoi(s.substr(3, 2));
        int year = stoi(s.substr(6, 4));
        dates[i][0] = day;
        dates[i][1] = month;
        dates[i][2] = year;
    }
    quickSort(dates, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (dates[i][0] < 10) cout << "0";
        cout << dates[i][0] << "-";

        if (dates[i][1] < 10) cout << "0";
        cout << dates[i][1] << "-" << dates[i][2] << endl;
    }
}