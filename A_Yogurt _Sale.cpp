#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // Option 1: Buy everything individually
    int cost_all_single = n * a;

    // Option 2: Buy as many pairs as possible using the promotion
    int pairs = n / 2;
    int remaining = n % 2;
    int cost_with_promo = (pairs * b) + (remaining * a);

    // The answer is the minimum of these two strategies
    cout << min(cost_all_single, cost_with_promo) << endl;
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