#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_dots = 0;
    bool three_consecutive = false;
    int consecutive_count = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            total_dots++;
            consecutive_count++;
            // Check if we hit the magic number 3
            if (consecutive_count >= 3) {
                three_consecutive = true;
            }
        } else {
            consecutive_count = 0;
        }
    }

    // If we found "...", we only need 2 actions to fill everything
    if (three_consecutive) {
        cout << 2 << endl;
    } else {
        // Otherwise, we must fill every single dot manually
        cout << total_dots << endl;
    }
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