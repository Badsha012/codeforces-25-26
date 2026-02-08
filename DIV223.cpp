#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;

    vector<long long> a(n);
    long long total_transferable_gain = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // Calculate how much this bank would contribute if its money was moved
        total_transferable_gain += (a[i] / x) * y;
    }

    long long max_money = 0;
    for (int i = 0; i < n; i++) {
        // Calculate total if bank i is the destination (it doesn't move its own money)
        long long current_bank_total = a[i] + (total_transferable_gain - (a[i] / x) * y);
        if (current_bank_total > max_money) {
            max_money = current_bank_total;
        }
    }

    cout << max_money << endl;
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