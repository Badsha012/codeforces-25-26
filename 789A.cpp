#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    // If the total sum cannot be evenly divided into 3 parts, it's impossible.
    if (total_sum % 3 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    long long target = total_sum / 3;
    long long current_prefix_sum = 0;
    long long first_cut_count = 0;
    long long total_ways = 0;

    // We look for split points. The second split point can at most be at index n-2 
    // (0-indexed), ensuring the 3rd part has at least the element at a[n-1].
    for (int i = 0; i < n - 1; ++i) {
        current_prefix_sum += a[i];

        // If we found a valid second cut point (summing up to 2 * target)
        // It can pair with any valid first cut point found strictly before this index.
        // Note: Check for 2*target first if target == 0 to avoid counting the same index twice.
        if (current_prefix_sum == 2 * target && i > 0) {
            total_ways += first_cut_count;
        }

        // If we found a valid first cut point (summing up to target)
        if (current_prefix_sum == target) {
            first_cut_count++;
        }
    }

    cout << total_ways << "\n";

    return 0;
}