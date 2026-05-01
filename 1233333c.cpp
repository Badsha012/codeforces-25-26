#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long len = 0;
    // Find the smallest integer i that does not divide n
    for (long long i = 1; ; ++i) {
        if (n % i != 0) {
            cout << i - 1 << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
