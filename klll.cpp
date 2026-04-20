#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void solve() {
    long long N;
    cin >> N;

    double root = sqrt(N);
    long long intRoot = round(root);

    // Check if it's a perfect square
    if (intRoot * intRoot == N) {
        // Check if the root is prime
        if (isPrime(intRoot)) {
            cout << "YES." << endl;
        } else {
            cout << "NO." << endl;
        }
    } else {
        // Not a perfect square, so sqrt(N) is not an integer/prime
        cout << "NO." << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}