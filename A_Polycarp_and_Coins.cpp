#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    long long c1 = n / 3;
    long long c2 = n / 3;

    // Handle the remainder
    if (n % 3 == 1) {
        c1++;
    } else if (n % 3 == 2) {
        c2++;
    }

    cout << c1 << " " << c2 << endl;
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}