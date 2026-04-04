#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Find the missing integer in a sequence of N+1 consecutive integers.
 * The input provides N integers.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: Sort the array to find the sequence order
    sort(a.begin(), a.end());

    // Step 2: Check for a gap between consecutive elements
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 1) {
            // The missing number is found in the gap
            cout << a[i] + 1 << endl;
            return;
        }
    }

    /* Note: If no gap is found within the array, the missing number 
       would technically be a[0]-1 or a[n-1]+1. However, based on 
       the example 4, 5, 7 -> 6, the missing number is always 
       inside the range of the given sequence.
    */
}

int main() {
    // Standard speedup for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}