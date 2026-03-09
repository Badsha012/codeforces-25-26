#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int x, k;
    cin >> x >> k;

    // Case 1: x is not divisible by k
    if (x % k != 0) {
        cout << 1 << endl;
        cout << x << endl;
    } 
    // Case 2: x is divisible by k
    else {
        cout << 2 << endl;
        // We split x into (x-1) and 1
        // Since x % k == 0, (x-1) % k cannot be 0 (for k > 1)
        // And 1 % k is only 0 if k == 1, but k >= 2 here.
        cout << x - 1 << " " << 1 << endl;
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