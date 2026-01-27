#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. Distance from start (0) to first station
    int max_gap = a[0];

    // 2. Distances between consecutive stations
    for (int i = 1; i < n; i++) {
        max_gap = max(max_gap, a[i] - a[i - 1]);
    }

    // 3. Distance from last station to x and back to last station
    // This is 2 * (x - last_station)
    int turnaround = 2 * (x - a[n - 1]);
    max_gap = max(max_gap, turnaround);

    cout << max_gap << endl;
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