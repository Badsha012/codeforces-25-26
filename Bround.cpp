#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i; // Store positions of each value
    }

    int L = -1;
    int target_val = -1;

    // 1. Find the first index that isn't the maximum possible value
    for (int i = 0; i < n; i++) {
        if (p[i] != n - i) {
            L = i;
            target_val = n - i;
            break;
        }
    }

 
    if (L == -1) {
        // Technically reversing a single element [n, n] changes nothing
        for (int i = 0; i < n; i++) cout << p[i] << (i == n - 1 ? "" : " ");
        cout << "\n";
        return;
    }

    // 2. Find where the target value is
    int R = pos[target_val];

    // 3. Reverse the segment [L, R]
    reverse(p.begin() + L, p.begin() + R + 1);

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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