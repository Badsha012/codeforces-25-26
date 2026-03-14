#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1) {
        // Easiest case: just use n ones
        cout << "YES" << endl;
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << 1 << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        // x is 1, so we must use numbers >= 2
        if (k == 1 || (k == 2 && n % 2 != 0)) {
            // If k is 1, no numbers left. 
            // If k is 2 and n is odd, sums of 2 will always be even.
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (n % 2 == 0) {
                // n is even: use n/2 twos
                cout << n / 2 << endl;
                for (int i = 0; i < n / 2; ++i) {
                    cout << 2 << (i == n / 2 - 1 ? "" : " ");
                }
                cout << endl;
            } else {
                // n is odd and k >= 3: use one 3 and the rest twos
                // Since n is odd and >= 3 (n >= x and x=1), (n-3) is even.
                cout << 1 + (n - 3) / 2 << endl;
                cout << 3;
                for (int i = 0; i < (n - 3) / 2; ++i) {
                    cout << " " << 2;
                }
                cout << endl;
            }
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