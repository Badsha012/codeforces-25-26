#include <iostream>

using namespace std;

void solve() {
    int a;
    cin >> a;

    // A regular polygon exists if the exterior angle (180 - a) 
    // divides 360 degrees perfectly.
    if (360 % (180 - a) == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}