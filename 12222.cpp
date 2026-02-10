#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Check if already not sorted
        bool notSorted = false;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] > a[i + 1]) {
                notSorted = true;
                break;
            }
        }

        if (notSorted) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i + 1 < n; i++) {
            long long gap = a[i + 1] - a[i];
            long long ops = gap / 2 + 1;
            ans = min(ans, ops);
        }

        cout << ans << "\n";
    }

    return 0;
}
