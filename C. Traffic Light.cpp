#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;

    // If the current color is already green, the wait is 0
    if (c == 'g') {
        cout << 0 << endl;
        return;
    }

    // Concatenate the string to handle cyclic behavior
    s += s;
    int max_dist = 0;
    int last_g = -1;

    // Traverse backwards to find the nearest 'g' for every 'c'
    for (int i = 2 * n - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            last_g = i;
        }
        if (i < n && s[i] == c) {
            // last_g is guaranteed to be found because 'g' exists in s
            max_dist = max(max_dist, last_g - i);
        }
    }

    cout << max_dist << endl;
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