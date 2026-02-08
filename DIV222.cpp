#include <iostream>

using namespace std;

/**
 * Problem: Lawn Mower
 * Logic: To prevent a mower of width W from exiting, we must ensure 
 * no gap reaches size W. We place a single board at every W-th position.
 * The number of boards kept is floor(n / w).
 */

void solve() {
    long long n, w;
    cin >> n >> w;

    // If the mower is wider than the fence, we can remove all boards
    if (w > n) {
        cout << n << endl;
    } else {
        // We must keep n/w boards to block the path
        long long kept = n / w;
        cout << n - kept << endl;
    }
}

int main() {
    // Faster I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}