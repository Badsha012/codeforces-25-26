#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    int first_closed = -1;
    int last_closed = -1;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            if (first_closed == -1) {
                first_closed = i;
            }
            last_closed = i;
        }
    }
    
    // The problem guarantees at least one closed door, 
    // so first_closed and last_closed will always be updated.
    
    int duration_needed = last_closed - first_closed + 1;
    
    if (duration_needed <= x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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