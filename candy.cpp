#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n < 5) {
        cout << -1 << '\n';
        return 0;
    }

    // Sliding window of size 5
    for (int i = 0; i + 4 < n; i++) {
        unordered_map<long long, int> freq;

        for (int j = i; j < i + 5; j++) {
            freq[a[j]]++;
        }

        long long target = -1;
        bool ok = false;

        for (auto &p : freq) {
            if (p.second == 4) {
                target = p.first;
                ok = true;
                break;
            }
        }

        if (ok) {
            // find the different candy
            for (int j = i; j < i + 5; j++) {
                if (a[j] != target) {
                    cout << (j + 1) << '\n'; // 1-based index
                    return 0;
                }
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
