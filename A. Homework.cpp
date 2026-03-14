#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    string a, b, c;

    // Read length and string a
    if (!(cin >> n >> a)) return;
    
    // Read length and strings b and c
    if (!(cin >> m >> b >> c)) return;

    // Process each character from b according to the distribution in c
    for (int i = 0; i < m; ++i) {
        if (c[i] == 'V') {
            // Vlad adds to the beginning
            a.insert(0, 1, b[i]);
        } else {
            // Dima adds to the end
            a.push_back(b[i]);
        }
    }

    cout << a << endl;
}

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}