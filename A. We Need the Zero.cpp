#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int current_xor_sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        current_xor_sum ^= a;
    }

    if (n % 2 != 0) {
        // If n is odd, x = current_xor_sum makes the total XOR sum 0
        cout << current_xor_sum << "\n";
    } else {
        // If n is even, the XOR sum remains current_xor_sum no matter what x is
        if (current_xor_sum == 0) {
            cout << 0 << "\n";
        } else {
            cout << -1 << "\n";
        }
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