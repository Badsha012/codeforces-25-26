#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int q;
    cin >> q;

    while (q--) {
        long long l, r;
        cin >> l >> r;

        // Find indices
        auto left = lower_bound(A.begin(), A.end(), l);
        auto right = upper_bound(A.begin(), A.end(), r);

        cout << right - left << "\n";
    }

    return 0;
}
