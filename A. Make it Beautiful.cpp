#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Since the input is sorted, if the first and last elements are the same,
    // then all elements in the array are the same.
    if (a[0] == a[n - 1]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        // Strategy: Swap the first element with the last element.
        // This puts the largest value at index 0 and the smallest at index 1.
        swap(a[0], a[n - 1]);
        
        // Alternatively, you could print a[n-1] first, then a[0], then a[1...n-2].
        // But swapping and printing the whole vector is cleaner.
        for (int i = 0; i < n; i++) {
            cout << a[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
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