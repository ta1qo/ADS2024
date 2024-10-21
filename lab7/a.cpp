#include <iostream>
#include <vector>

using namespace std;

bool check(string s1, string s2) {
    return s1.size() <= s2.size();
}

void mergeHalves(vector <string> &arr, string temp[], int leftStart, int rightEnd) {
    int leftEnd = (rightEnd + leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (check(arr[left], arr[right])) {
            temp[index] = arr[left];
            left++;
        } else {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    while (left <= leftEnd) {
        temp[index] = arr[left];
        index++;
        left++;
    }
    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++;
        right++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergesort(vector <string> &arr, string temp[], int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) return;
    int middle = (leftStart + rightEnd) / 2;
    mergesort(arr, temp, leftStart, middle);
    mergesort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd); 
}

int main() {
    int n; cin >> n;
    vector <vector <string> > arr(n);
    for (int i = 0; i < n; i++) {
        while (true) {
            string x; cin >> x;
            arr[i].push_back(x);
            if (cin.peek() == '\n')
                break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        mergesort(arr[i], new string[arr[i].size()], 0, arr[i].size() - 1);
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}