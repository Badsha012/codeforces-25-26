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

    // Sort to easily group the largest elements
    sort(a.begin(), a.end());

    // If the smallest and largest elements are the same, 
    // all elements are identical, making a valid partition impossible.
    if (a[0] == a[n - 1]) {
        cout << -1 << endl;
        return;
    }

    vector<int> b, c;
    int max_val = a[n - 1];
    
    // Move all instances of the maximum value to c, others to b
    for (int i = 0; i < n; i++) {
        if (a[i] == max_val) {
            c.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }

    // Output lengths
    cout << b.size() << " " << c.size() << endl;

    // Output array b
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << (i == b.size() - 1 ? "" : " ");
    }
    cout << endl;

    // Output array c
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << (i == c.size() - 1 ? "" : " ");
    }
    cout << endl;
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