#include <iostream>

using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;

    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2) {
        cout << m << endl;
    } else {
        // For n >= 3, we can always achieve 2*m 
        // by placing m between two zeros: [0, m, 0, 0...]
        cout << 2 * m << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}