#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: C. Ski Resort
 * Strategy: Identify contiguous segments of "valid" days (temp <= q).
 * For a segment of length L, if L >= k, the number of valid sub-segments
 * is the sum of integers from 1 to (L - k + 1).
 */

void solve() {
    int n, k;
    long long q;
    cin >> n >> k >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_ways = 0;
    long long current_segment_len = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= q) {
            current_segment_len++;
        } else {
            // End of a valid segment reached
            if (current_segment_len >= k) {
                long long m = current_segment_len - k + 1;
                total_ways += (m * (m + 1)) / 2;
            }
            current_segment_len = 0;
        }
    }

    // Check the last segment if the array ended while in a valid segment
    if (current_segment_len >= k) {
        long long m = current_segment_len - k + 1;
        total_ways += (m * (m + 1)) / 2;
    }

    cout << total_ways << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}