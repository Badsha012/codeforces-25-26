#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // Use a frequency array. Size n+1 because values are 1 to n.
    vector<int> cnt(n + 1, 0);
    int ans = -1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        // Increment frequency
        cnt[x]++;
        
        // If we found our winner, store it
        if (cnt[x] >= 3) {
            ans = x;
        }
    }

    cout << ans << endl;
}

int main() {
    // Fast I/O is important for large input sizes
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}