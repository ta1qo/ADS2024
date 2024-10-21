#include <iostream>
#include <vector>
using namespace std;

struct Sorted {
    vector <int> values;
    int sum;

    Sorted(vector <int> values, int sum) {
        this->values = values;
        this->sum = sum;
    }

    bool check(Sorted other) {
        if (this->sum == other.sum) {
            int i = 0;
            while (i < values.size()) {
                if (this->values[i] == other.values[i]) {
                    i++;
                    continue;
                } else {
                    return this->values[i] < other.values[i];
                }
            }
        }
        return this->sum > other.sum;
    }
};

void mergeHalves(vector <Sorted> &arr, vector <Sorted> &temp, int leftStart, int rightEnd) {
    int leftEnd = (rightEnd + leftStart) / 2;
    int rightStart = leftEnd + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd) {
        if (arr[left].check(arr[right])) {
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

void mergesort(vector <Sorted> &arr, vector <Sorted> &temp, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) return;
    int middle = (leftStart + rightEnd) / 2;
    mergesort(arr, temp, leftStart, middle);
    mergesort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd); 
}

int main() {
    int n, m; cin >> n >> m;
    int a[n][m];
    vector <Sorted> result;
    vector <Sorted> temp(n, Sorted(vector <int> (m, 0), 0));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector <int> tmp(m);
        for (int j = 0; j < m; j++) {
            int x; cin >> tmp[j];
            sum += tmp[j];
        }
        result.push_back(Sorted(tmp, sum));
    }
    mergesort(result, temp, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i].values[j] << " ";
        }
        cout <<"\n";
    }
}