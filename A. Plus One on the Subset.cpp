#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int max_val = 0;
    int min_val = 2e9; // Initialize with a value larger than any possible input

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_val) max_val = a[i];
        if (a[i] < min_val) min_val = a[i];
    }

    // The answer is the difference between the largest and smallest element
    cout << max_val - min_val << endl;
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