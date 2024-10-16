#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    double gpa;
    string first;
    string last;

    Student(double gpa, string first, string last) {
        this->gpa = gpa;
        this->first = first;
        this->last = last;
    }

    bool check(string a, string b) {
        int size = 0;
        if (a.size() < b.size()) size = a.size();
        else size = b.size();
        
        for (int i = 0; i < size; i++) {
            if (a[i] < b[i]) return true;
            else if (a[i] > b[i]) return false;
        }
        if (size == a.size()) return true;
        else return false;
    }

    bool main_check(Student b) {
        if (this->gpa < b.gpa) return true;
        else if (this->gpa == b.gpa) {
            if (this->first == b.first) {
                return check(this->last, b.last);
            }
            else {
                return check(this->first, b.first);
            }
        }
        return false;
    }
};

struct Heap {
    vector<Student> heap;

    int parent(int i) {return (i-1)/2;}
    int left(int i) {return (i*2)+1;}
    int right(int i) {return (i*2)+2;}

    void insert(Student val) {
        heap.push_back(val);
        int i = heap.size()-1;
        while (i != 0 && heap[i].main_check(heap[parent(i)])) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    Student heapDown() {
        if (heap.size() == 0) return Student(0,"","");
        if (heap.size() == 1) {
            Student min = heap[0];
            heap.pop_back();
            return min; 
        }
        Student min = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        heapify(0);
        return min;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap.size() && heap[l].main_check(heap[smallest])) smallest = l;
        if (r < heap.size() && heap[r].main_check(heap[smallest])) smallest = r;
        if (smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    void print() {
        while (heap.size() != 0) {   
            Student student = heapDown();
            cout << student.first << " " << student.last << " " << fixed << setprecision(3) << student.gpa << '\n';
        }
    }
};

int main() {
    int n; cin>>n;
    map<string,double> marks; 
    marks["F"] = 0.0;
    marks["D"] = 1.0;
    marks["D+"] = 1.5;
    marks["C"] = 2.0;
    marks["C+"] = 2.5;
    marks["B"] = 3.0;
    marks["B+"] = 3.5;
    marks["A"] = 3.75;
    marks["A+"] = 4.0;

    vector<Student> students;

    Heap h;

    for (int i = 0; i < n; i++) {
        string first, last; cin >> first >> last;
        int num; cin >> num;
        int credits = 0;
        double score = 0;
        for (int j = 0; j < num; j++) {
            string mark; int credit;
            cin >> mark >> credit;
            score += marks[mark] * credit;
            credits += credit;
        }
        double gpa = score/credits;
        Student student = Student(gpa, first, last);
        students.push_back(student);
        h.insert(student);    
    }
    
    h.print();
}