#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: C. Alternating Subsequence
 * Strategy: Divide the array into contiguous blocks of the same sign.
 * From each block, pick the maximum element to ensure the max total sum.
 */

// Helper function to check if two numbers have the same sign
bool same_sign(long long a, long long b) {
    return (a > 0 && b > 0) || (a < 0 && b < 0);
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        long long current_val = a[i];
        int j = i;
        
        // Find the maximum element in the current contiguous block of same-sign numbers
        while (j < n && same_sign(a[i], a[j])) {
            current_val = max(current_val, a[j]);
            j++;
        }
        
        total_sum += current_val;
        // Move i to the end of the current block
        i = j - 1;
    }

    cout << total_sum << "\n";
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