#include <iostream>

using namespace std;

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // Condition 1: We cannot move downwards.
    if (d < b) {
        cout << -1 << endl;
        return;
    }

    // After moving up-right (d - b) times, the x-coordinate becomes:
    long long current_x = a + (d - b);

    // Condition 2: We can only move left, so current_x must be >= c.
    if (current_x < c) {
        cout << -1 << endl;
        return;
    }

    // Total moves = (moves to reach target y) + (moves to reach target x from there)
    long long moves = (d - b) + (current_x - c);
    cout << moves << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}