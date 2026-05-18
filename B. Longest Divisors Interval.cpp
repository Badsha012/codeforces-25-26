#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    long long ans = 1;
    // Find the first integer that does not divide n
    while (n % ans == 0) {
        ans++;
    }
    
    // The maximum interval size is ans - 1
    cout << ans - 1 << "\n";
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