#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n + 2), b(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        // best[i] = max(b[i..n])
        vector<long long> best(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            best[i] = max(best[i + 1], b[i]);
        }

        // c[i] = max(a[i], best[i])
        vector<long long> pref(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            long long c = max(a[i], best[i]);
            pref[i] = pref[i - 1] + c;
        }

        // Answer queries
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l - 1] << " ";
        }
        cout << "\n";
    }

    return 0;
}
