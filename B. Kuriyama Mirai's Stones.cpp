#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Use long long to prevent overflow (v_i can be 10^9, n is 10^5)
    vector<long long> v(n + 1, 0);
    vector<long long> u(n + 1, 0);
    vector<long long> prefix_v(n + 1, 0);
    vector<long long> prefix_u(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        u[i] = v[i];
    }

    // Prepare the sorted array for Type 2 queries
    sort(u.begin() + 1, u.end());

    // Pre-calculate prefix sums
    // prefix[i] = element[1] + ... + element[i]
    for (int i = 1; i <= n; i++) {
        prefix_v[i] = prefix_v[i - 1] + v[i];
        prefix_u[i] = prefix_u[i - 1] + u[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            // Range sum for original array: prefix[r] - prefix[l-1]
            cout << prefix_v[r] - prefix_v[l - 1] << "\n";
        } else {
            // Range sum for sorted array
            cout << prefix_u[r] - prefix_u[l - 1] << "\n";
        }
    }

    return 0;
}