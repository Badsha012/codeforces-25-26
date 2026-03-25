#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string r = s;
    sort(r.begin(), r.end());

    if (r == s) {
        // If sorting didn't change it, try reversing
        reverse(r.begin(), r.end());
    }

    if (r == s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << r << endl;
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
