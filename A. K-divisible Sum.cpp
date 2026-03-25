#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    // Find the smallest multiple of k that is >= n
    long long factor = (n + k - 1) / k;
    long long target_sum = factor * k;

    // Distribute target_sum across n elements as evenly as possible
    // The max element is ceil(target_sum / n)
    long long ans = (target_sum + n - 1) / n;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
