#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s, t;
    
    if (!(cin >> n >> s >> t)) return;

   
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}