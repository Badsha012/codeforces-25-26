#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    
    // If we can buy a single package containing all n shovels
    if (k >= n) {
        cout << 1 << "\n";
        return;
    }
    
    long long max_package_size = 1;
    
    // Find all divisors of n up to sqrt(n)
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            // i is a divisor
            if (i <= k) {
                max_package_size = max(max_package_size, i);
            }
            // n / i is the paired divisor
            if (n / i <= k) {
                max_package_size = max(max_package_size, n / i);
            }
        }
    }
    
    // The minimum number of packages is n divided by the largest valid package size
    cout << n / max_package_size << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}