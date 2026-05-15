#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int operations = 0;

    // Process from right to left
    for (int i = n - 2; i >= 0; i--) {
        while (a[i] >= a[i + 1] && a[i] > 0) {
            a[i] /= 2;
            operations++;
        }
        // If two adjacent elements become equal (e.g., both 0), it's impossible
        if (a[i] >= a[i + 1]) {
            cout << -1 << "\n";
            return;
        }
    }

    cout << operations << "\n";
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