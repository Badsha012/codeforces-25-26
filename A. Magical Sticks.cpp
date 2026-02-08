#include <iostream>

using namespace std;

/**
 * Problem: Magical Sticks
 * Logic: To maximize sticks of equal length, we pair 1 with (n-1), 
 * 2 with (n-2), etc., to match the length of n.
 */

void solve() {
    long long n;
    cin >> n;
    
    // The formula (n + 1) / 2 using integer division 
    // effectively handles both even and odd cases.
    long long result = (n + 1) / 2;
    
    cout << result << endl;
}

int main() {
    // Optimizing I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}