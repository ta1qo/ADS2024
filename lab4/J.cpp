    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    void balanced(vector<int>& v, int left, int right, vector<int>& res, int& index) {
        if (left > right) return;
        int mid = left + (right - left) / 2;    
        res[index++] = (v[mid]);
        balanced(v, left, mid - 1, res, index);
        balanced(v, mid + 1, right, res, index);
    }

    int main() {
        int n; cin >> n;
        int size = (1 << n) - 1;
        vector<int> v(size), res(size);
        for (int i = 0; i < size; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int index = 0;
        balanced(v, 0, size - 1, res, index);
        for (int i = 0; i < size; i++) {
            cout << res[i] << ' ';
        }
        return 0;
    }
