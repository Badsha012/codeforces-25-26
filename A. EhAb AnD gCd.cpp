#include <iostream>

using namespace std;

void solve() {
    int x;
    if (!(cin >> x)) return;
    
    // The simplest pair is always (1, x-1)
    // because GCD(1, x-1) = 1 and LCM(1, x-1) = x-1
    // 1 + x - 1 = x
    cout << 1 << " " << x - 1 << "\n";
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