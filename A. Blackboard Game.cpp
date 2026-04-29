#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Bob wins if n is a multiple of 4, otherwise Alice wins
    if (n % 4 == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
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