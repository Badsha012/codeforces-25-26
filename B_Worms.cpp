#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // We store the cumulative count of worms.
    // prefix_sums[i] will store the label of the last worm in pile i+1.
    vector<int> prefix_sums(n);
    int current_sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        current_sum += a;
        prefix_sums[i] = current_sum;
    }

    int m;
    cin >> m;
    while (m--) {
        int q;
        cin >> q;

        // lower_bound finds the first element in the range [first, last) 
        // which has a value not less than q.
        auto it = lower_bound(prefix_sums.begin(), prefix_sums.end(), q);
        
        // The pile number is the index + 1 (since piles are 1-indexed).
        cout << (distance(prefix_sums.begin(), it) + 1) << "\n";
    }

    return 0;
}