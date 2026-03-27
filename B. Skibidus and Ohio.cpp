#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    bool has_pair = false;
    // Check if any two adjacent characters are the same
    for (int i = 0; i < (int)s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            has_pair = true;
            break;
        }
    }

    if (has_pair) {
        // If a pair exists, we can always reduce the string to length 1
        cout << 1 << "\n";
    } else {
        // Otherwise, no operations can be performed
        cout << s.length() << "\n";
    }
}

int main() {
    // Standard competitive programming I/O optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}