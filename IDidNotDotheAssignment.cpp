#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false; // 1 and below are not prime
    if (n == 2) return true;  // 2 is prime
    if (n % 2 == 0) return false; // even numbers >2 are not prime
    for (int i = 3; i*i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << "NO PUNISHMENT" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "I DID NOT DO THE ASSIGNMENT." << endl;
        }
    }

    return 0;
}
