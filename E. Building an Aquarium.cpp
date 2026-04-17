#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Function to calculate total water needed for a given height h
bool can_fill(const vector<int>& a, ll h, ll x) {
    ll total_water = 0;
    for (int height : a) {
        if (h > height) {
            total_water += (h - height);
        }
        // Optimization: if water exceeds x early, return false
        if (total_water > x) return false;
    }
    return total_water <= x;
}

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll low = 1, high = 2e9 + 7; // Sufficiently large upper bound
    ll ans = 1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (can_fill(a, mid, x)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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