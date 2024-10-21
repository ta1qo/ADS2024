#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

map <string, double> grades;

struct Students {
    string first, last;
    double gpa;

    Students(string s1, string s2, double gpa) {
        this->last = s1;
        this->first = s2;
        this->gpa = gpa;
    }

    bool check(Students other) {
        if (this->gpa < other.gpa) {
            return true; 
        } else if (this->gpa == other.gpa && this->last < other.last) {
            return true;
        } else if (this->gpa == other.gpa && this->last == other.last && this->first < other.first) {
            return true;
        }
        return false;
    }
};

void mergeHalves(vector <Students> &arr, vector <Students> &temp, int leftStart, int rightEnd) {
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
        index++; left++;
    }
    while (right <= rightEnd) {
        temp[index] = arr[right];
        index++; right++;
    }
    for (int i = leftStart; i <= rightEnd; i++) {
        arr[i] = temp[i];
    }
}

void mergesort(vector <Students> &arr, vector <Students> &temp, int leftStart, int rightEnd) {
    if (leftStart >= rightEnd) return;
    int middle = (leftStart + rightEnd) / 2;
    mergesort(arr, temp, leftStart, middle);
    mergesort(arr, temp, middle + 1, rightEnd);
    mergeHalves(arr, temp, leftStart, rightEnd); 
}

double gpa(pair<string, int> a[], int num) {
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < num; i++) {
        sum1 += grades[a[i].first] * a[i].second;
        sum2 += a[i].second;
    }
    return sum1/sum2;
}

int main() {
    int n; cin >> n;
    grades.insert(make_pair("A+", 4.0));
    grades.insert(make_pair("A", 3.75));
    grades.insert(make_pair("B+", 3.5));
    grades.insert(make_pair("B", 3.0));
    grades.insert(make_pair("C+", 2.5));
    grades.insert(make_pair("C", 2.0));
    grades.insert(make_pair("D+", 1.5));
    grades.insert(make_pair("D", 1.0));
    grades.insert(make_pair("F", 0));
    vector <Students> students;
    for (int i = 0; i < n; i++) {
        int num; string s1, s2;
        cin >> s1 >> s2 >> num;
        pair <string, int> subjects[num];
        for (int j = 0; j < num; j++) {
            cin >> subjects[j].first >> subjects[j].second;
        }
        students.push_back(Students(s1, s2, gpa(subjects, num)));
    }
    vector <Students> temp (n, Students("", "", 0));
    mergesort(students, temp, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << students[i].last << " " << students[i].first << " ";
        cout << setprecision(3) << fixed << students[i].gpa << "\n";
    }

    return 0;
}