#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    char max_char = 'a';
    for (char c : s) {
        if (c > max_char) {
            max_char = c;
        }
    }

    // Calculate alphabet size: 'a' is 1, 'b' is 2, etc.
    int result = max_char - 'a' + 1;
    cout << result << endl;
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