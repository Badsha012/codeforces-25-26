#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // To satisfy a[i] + b[i] <= a[i+1] + b[i+1],
    // we can simply make a[i] + b[i] = n + 1 for all i.
    for (int i = 0; i < n; i++) {
        int b_i = (n + 1) - a[i];
        cout << b_i << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}