#include <iostream>

using namespace std;

void solve() {
    long long l, r;
    cin >> l >> r;

    // The smallest possible LCM for any x >= l is LCM(x, 2x) = 2x.
    // To keep it within [l, r], we check the smallest possible x, which is l.
    if (2 * l <= r) {
        cout << l << " " << 2 * l << "\n";
    } else {
        cout << "-1 -1\n";
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