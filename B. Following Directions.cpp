#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int x = 0, y = 0;
    bool found_candy = false;

    for (int i = 0; i < n; i++) {
        // Update coordinates based on direction
        if (s[i] == 'U') {
            y++;
        } else if (s[i] == 'D') {
            y--;
        } else if (s[i] == 'L') {
            x--;
        } else if (s[i] == 'R') {
            x++;
        }

        // Check if we are currently at the candy's position
        if (x == 1 && y == 1) {
            found_candy = true;
        }
    }

    if (found_candy) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}