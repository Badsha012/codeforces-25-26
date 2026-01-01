#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long x;
    bool hasZero = false;
    long long ans = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 0) {
            hasZero = true;
        }

        ans = min(ans, llabs(x));
    }

    if (hasZero) {
        cout << 0 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
