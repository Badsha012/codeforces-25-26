#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int neg = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1) neg++;
        }

        int operations = 0;

        // Step 1: Make sum >= 0
        while (neg > n - neg) {
            neg--;       // convert -1 to 1
            operations++;
        }

        // Step 2: Make number of -1 even
        if (neg % 2 == 1) {
            operations++;
        }

        cout << operations << "\n";
    }

    return 0;
}