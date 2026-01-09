#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, l, r;
        cin >> n >> l >> r;

        long long cntR = n - r + 1;

        long long sumR = (r + n) * cntR / 2;     // sum of R from r to n
        long long sumL = l * (l + 1) / 2;        // sum of L from 1 to l

        long long ans = l * sumR
                      - cntR * sumL
                      + l * cntR;

        cout << ans << '\n';
    }
    return 0;
}
