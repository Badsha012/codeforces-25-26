#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int count0 = 0, count1 = 0;
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }

    int n = s.length();
    int i = 0;
    for (i = 0; i < n; ++i) {
        if (s[i] == '0') {
            // We need a '1' to put at this position
            if (count1 > 0) count1--;
            else break; // No '1's left to satisfy t[i] != s[i]
        } else {
            // We need a '0' to put at this position
            if (count0 > 0) count0--;
            else break; // No '0's left to satisfy t[i] != s[i]
        }
    }

    // The characters from index i to n-1 must be deleted
    cout << n - i << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}