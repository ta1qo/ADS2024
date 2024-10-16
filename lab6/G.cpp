#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int partition (int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left-1;
    for (int j = left; j <= right-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quickSort (int arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index-1);
    quickSort(arr, index+1, right);
}

int main() {
    int n; cin >> n;
    map <string, string> name;
    for (int i = 0; i < n; i++) {
        string s1; cin >> s1;
        string s2; cin >> s2;
        bool found = false;
        for (auto it = name.begin(); it != name.end(); it++) {
            if (it->second == s1) {
                name[it->first] = s2;
                found = true;
                break;
            }
        }
        if (!found) name[s1] = s2;
    }
    
    cout << name.size() << "\n";
    for (auto it = name.begin(); it != name.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }
}