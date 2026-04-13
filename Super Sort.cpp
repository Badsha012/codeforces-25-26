#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, K;
int A[20];
int memo[1 << 18][19];

// DP with Bitmask to check if a valid path exists to the end
int solve_dp(int mask, int last) {
    if (mask == (1 << N) - 1) return 1;
    if (memo[mask][last] != -1) return memo[mask][last];

    int res = 0;
    for (int j = 0; j < N; ++j) {
        if (!(mask & (1 << j))) {
            // Check if this is the first element or if the difference is <= K
            if (last == N || abs(A[last] - A[j]) <= K) {
                if (solve_dp(mask | (1 << j), j)) {
                    res = 1;
                    break;
                }
            }
        }
    }
    return memo[mask][last] = res;
}

void solve() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Sort to handle lexicographical requirement
    sort(A, A + N);

    memset(memo, -1, sizeof(memo));

    // Check if any solution exists
    if (!solve_dp(0, N)) {
        cout << "No Solution" << endl;
        return;
    }

    // Reconstruct the lexicographically smallest path
    int mask = 0;
    int last = N;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(mask & (1 << j))) {
                if (last == N || abs(A[last] - A[j]) <= K) {
                    // If picking A[j] leads to a valid completion, pick it
                    if (solve_dp(mask | (1 << j), j)) {
                        result.push_back(A[j]);
                        mask |= (1 << j);
                        last = j;
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}