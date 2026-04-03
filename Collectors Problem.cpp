#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Total Profit = (Sum of all D_i) - (N * P_i) - S_i
 * We use long long to prevent overflow since values can reach 10^9 and N is 2*10^5.
 */

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<long long> P(M), S(M), D(N);
    for (int i = 0; i < M; ++i) cin >> P[i];
    for (int i = 0; i < M; ++i) cin >> S[i];
    
    long long sum_D = 0;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        sum_D += D[i];
    }

    long long max_profit = -2e18; // Initialize with a very small number

    for (int i = 0; i < M; ++i) {
        // Net gain from accounts = Total current money - (Target * Number of people)
        long long current_net = sum_D - ((long long)N * P[i]);
        // Final profit = Net gain - cost of package
        long long final_profit = current_net - S[i];

        if (final_profit > max_profit) {
            max_profit = final_profit;
        }
    }

    // Output formatting
    if (max_profit > 0) {
        cout << "Profit " << max_profit << endl;
    } else if (max_profit < 0) {
        cout << "Loss " << abs(max_profit) << endl;
    } else {
        cout << "Neutral" << endl;
    }

    return 0;
}