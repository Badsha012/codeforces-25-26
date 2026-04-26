#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = stoi(s);
    
    int root = round(sqrt(n));
    
    if (root * root == n) {
        // We need a + b = root. 
        // a = 0 and b = root is always a valid solution.
        cout << 0 << " " << root << endl;
    } else {
        cout << -1 << endl;
    }
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