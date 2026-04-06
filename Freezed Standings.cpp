#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * String T = S repeated K times. |S| = N.
 * Total distinct substrings = N * (N * K)
 * Distinct substrings with NO repeats = N * N 
 * (Lengths 1 to N each have N distinct cyclic shifts)
 * Result = (Total) - (No Repeats) = N^2 * K - N^2 = N^2 * (K - 1)
 */

int main() {
    long long n, k;
    if (!(cin >> n >> k)) return 0;

    long long MOD = 998244353;

    // We need to calculate (n % MOD) * (n % MOD) * ((k - 1) % MOD)
    long long n_mod = n % MOD;
    long long k_minus_1_mod = (k - 1) % MOD;

    // Calculate step by step to prevent overflow before modulo
    long long ans = (n_mod * n_mod) % MOD;
    ans = (ans * k_minus_1_mod) % MOD;

    cout << ans << endl;

    return 0;
}