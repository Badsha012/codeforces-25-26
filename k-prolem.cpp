#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<ll>> grid(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // dp[i][j][0] = max sum without doubling a max value
    // dp[i][j][1] = max sum with one value doubled
    vector<vector<ll>> dp0(n, vector<ll>(n, 0));
    vector<vector<ll>> dp1(n, vector<ll>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll val = grid[i][j];
            if (i == 0 && j == 0) {
                dp0[i][j] = val;
                dp1[i][j] = val * 2;
            } else {
                ll best0 = -1, best1 = -1;
                
                // From Top
                if (i > 0) {
                    best0 = max(best0, dp0[i-1][j]);
                    best1 = max(best1, dp1[i-1][j]);
                }
                // From Left
                if (j > 0) {
                    best0 = max(best0, dp0[i][j-1]);
                    best1 = max(best1, dp1[i][j-1]);
                }

                dp0[i][j] = val + best0;
                // dp1 is either (previous path with a double) + current 
                // OR (previous path without a double) + current doubled
                dp1[i][j] = max(val + best1, (2 * val) + best0);
            }
        }
    }

    cout << dp1[n-1][n-1] << "\n";
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