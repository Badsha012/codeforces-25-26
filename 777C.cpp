#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the segments in ascending order
    sort(a.begin(), a.end());

    // Check consecutive triplets
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            cout << "YES\n";
            return 0; // Found a valid triangle, exit early
        }
    }

    // If no triplet satisfies the condition
    cout << "NO\n";

    return 0;
}