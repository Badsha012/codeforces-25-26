#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int total_points = 0;
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            char cell;
            cin >> cell;
            if (cell == 'X') {
                // Calculate distance to the closest edge
                // The +1 converts 0-indexed distance to 1-indexed points
                int ring_score = min({r, 9 - r, c, 9 - c}) + 1;
                total_points += ring_score;
            }
        }
    }
    cout << total_points << endl;
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