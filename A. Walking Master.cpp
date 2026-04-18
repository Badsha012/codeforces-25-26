#include <iostream>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d < b || c > a + (d - b)) {
        cout << -1 << endl;
    } else {
        long long moves = (d - b) + (a + d - b - c);
        cout << moves << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}