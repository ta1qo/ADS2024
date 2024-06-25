#include<iostream>
// #include<cmath>
using namespace std;

string isPrime(int x) {
    if (x < 2) return "NO";
    
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return "NO";
    }

    return "YES";
}

// bool issPrime(int num) {
//         if(num <= 1) return false;
//         if (num <= 3)  return true; 
        
//         int range = sqrt(num);
//         // This is checked so that we can skip 
//         // middle five numbers in below loop 
//         if (num % 2 == 0 || num % 3 == 0) 
//             return false; 
        

//         for (int i = 5; i <= range; i += 6) 
//             if (num % i == 0 || num % (i + 2) == 0) 
//                 return false; 
        
//         return true;
//     }

int main() {
    int n; 
    cin >> n;
    cout << isPrime(n);
    
    return 0;
}