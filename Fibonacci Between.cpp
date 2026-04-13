#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    long long a = 0;
    long long b = 1;

    // Handle the first number (0) separately
    if (a >= L && a <= R) {
        cout << a << "\n";
    }

    // Handle the second number (1) separately to avoid duplicates
    if (b >= L && b <= R) {
        cout << b << "\n";
    }

    // Generate subsequent Fibonacci numbers
    while (true) {
        long long next = a + b;
        
        // If the next number exceeds the range, stop
        if (next > R) break;

        // Print if it's within the range [L, R]
        // Note: 'next' will be at least 2 here, so no duplicate 1s
        if (next >= L) {
            cout << next << "\n";
        }

        // Update values for the next iteration
        a = b;
        b = next;
    }

    return 0;
}