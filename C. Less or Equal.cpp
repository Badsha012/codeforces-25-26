#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans;

    if (k == 0) {
        // If we want 0 elements <= x, x must be smaller than the smallest element.
        // The smallest possible x is 1.
        ans = a[0] - 1;
        if (ans < 1) {
            cout << -1 << endl;
            return 0;
        }
    } else if (k == n) {
        // All elements are <= the last element.
        ans = a[n - 1];
    } else {
        // Check if the k-th element is the same as the (k+1)-th element.
        // a[k-1] is the k-th smallest element.
        if (a[k - 1] == a[k]) {
            cout << -1 << endl;
            return 0;
        } else {
            ans = a[k - 1];
        }
    }

    // Final check for the problem's range constraint [1, 10^9]
    if (ans >= 1 && ans <= 1000000000) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}