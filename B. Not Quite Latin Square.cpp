#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string rows[3];
    int target_row = -1;

    for (int i = 0; i < 3; ++i) {
        cin >> rows[i];
        // Check if this row contains the missing letter
        for (char c : rows[i]) {
            if (c == '?') {
                target_row = i;
            }
        }
    }

    // Frequency array for A, B, and C
    // 'A' maps to index 0, 'B' to 1, 'C' to 2
    bool present[3] = {false, false, false};

    for (char c : rows[target_row]) {
        if (c == 'A') present[0] = true;
        if (c == 'B') present[1] = true;
        if (c == 'C') present[2] = true;
    }

    // Output the letter that wasn't found in the target row
    if (!present[0]) cout << 'A' << endl;
    else if (!present[1]) cout << 'B' << endl;
    else if (!present[2]) cout << 'C' << endl;
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