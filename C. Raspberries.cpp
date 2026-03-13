#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    int min_ops = k; // Initialize with max possible cost
    int even_count = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        
        // Count evens for the k=4 case
        if (a[i] % 2 == 0) even_count++;

        // Standard cost to make one element divisible by k
        int rem = a[i] % k;
        if (rem == 0) {
            min_ops = 0;
        } else {
            min_ops = min(min_ops, k - rem);
        }
    }

    if (k == 4) {
        // Special logic for 4: We can either make one number divisible by 4
        // OR make two numbers divisible by 2.
        int cost_for_two_evens = max(0, 2 - even_count);
        min_ops = min(min_ops, cost_for_two_evens);
    }

    cout << min_ops << endl;
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