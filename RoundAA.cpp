#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << i << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}