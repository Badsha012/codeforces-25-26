#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int max_run = 1;
    int current_run = 1;

    // Find the longest sequence of identical characters
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            current_run++;
        } else {
            current_run = 1;
        }
        max_run = max(max_run, current_run);
    }

    // The minimum cost is the longest run + 1
    cout << max_run + 1 << endl;
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