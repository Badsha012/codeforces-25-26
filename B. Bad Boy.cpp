#include <iostream>

using namespace std;

void solve() {
    long long n, m, i, j;
    cin >> n >> m >> i >> j;
    
    // Always placing at the opposite corners (top-left and bottom-right)
    // guarantees the maximum total path length from any starting position.
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}