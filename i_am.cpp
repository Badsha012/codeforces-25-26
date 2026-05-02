#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // If we can buy one package that contains all n shovels
    if (k >= n) {
        cout << 1 << "\n";
        return;
    }

    long long max_divisor = 1;

    // Iterate up to sqrt(n) to find divisors
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // Check divisor i
            if (i <= k) {
                max_divisor = max(max_divisor, i);
            }
            // Check the paired divisor n/i
            if (n / i <= k) {
                max_divisor = max(max_divisor, n / i);
            }
        }
    }

    cout << n / max_divisor << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}