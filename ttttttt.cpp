#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    for (int op = 0; op <= 5; ++op) {
        // Check if s is a substring of x
        if (x.find(s) != string::npos) {
            cout << op << endl;
            return;
        }
        // Double the string x
        x += x;
    }

    // If we haven't found it after 5 doublings, it's not possible
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}