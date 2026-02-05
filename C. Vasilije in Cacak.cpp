#include <iostream>

using namespace std;

/**
 * Solves a single test case for Vasilije in Cacak.
 * Uses long long to handle sums up to 4e10.
 */
void solve() {
    long long n, k, x;
    cin >> n >> k >> x;

    // Minimum sum: 1 + 2 + ... + k
    long long min_sum = k * (k + 1) / 2;

    // Maximum sum: (n-k+1) + ... + n
    // Calculated as (sum of 1 to n) - (sum of 1 to n-k)
    long long max_sum = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

    if (x >= min_sum && x <= max_sum) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}