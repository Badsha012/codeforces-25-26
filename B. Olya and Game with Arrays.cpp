#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    long long min_of_min1 = 2e9; // Global smallest element
    long long min_of_min2 = 2e9; // Smallest "second-smallest" element
    long long sum_min2 = 0;      // Sum of all second-smallest elements

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        vector<int> a(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[j];
        }

        // Find the two smallest elements in the current array
        sort(a.begin(), a.end());
        
        int m1 = a[0];
        int m2 = a[1];

        if (m1 < min_of_min1) min_of_min1 = m1;
        if (m2 < min_of_min2) min_of_min2 = m2;
        sum_min2 += m2;
    }

    // If there's only one array, beauty is just its minimum
    if (n == 1) {
        cout << min_of_min1 << endl;
    } else {
        // Total beauty = sum of all second minimums 
        // minus the smallest second minimum (to make room)
        // plus the smallest first minimum (the new floor)
        long long result = sum_min2 - min_of_min2 + min_of_min1;
        cout << result << endl;
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