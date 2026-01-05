#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long A = max(0LL, max(b, c) + 1 - a);
        long long B = max(0LL, max(a, c) + 1 - b);
        long long C = max(0LL, max(a, b) + 1 - c);

        cout << A << " " << B << " " << C << "\n";
    }
    return 0;
}
