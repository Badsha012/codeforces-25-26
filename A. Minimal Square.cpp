#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    // 1. Identify the smaller and larger sides of the single rectangle
    int small = min(a, b);
    int large = max(a, b);

    // 2. We want to double the smaller side and compare it to the larger side
    // The side of our square must be at least 2*small AND at least large
    int side = max(2 * small, large);

    // 3. Output the area
    cout << side * side << endl;
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