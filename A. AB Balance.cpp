#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    // If the first and last characters are already identical, AB(s) == BA(s)
    if (s[0] == s[n - 1]) {
        cout << s << "\n";
    } else {
        // Change the first character to match the last character
        s[0] = s[n - 1];
        cout << s << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}