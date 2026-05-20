#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Helper function to calculate factorial for combinations
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r; // Optimize calculations
    
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int target = 0;
    for (char c : s1) {
        if (c == '+') target++;
        else target--;
    }

    int current = 0;
    int unrecognized = 0;
    for (char c : s2) {
        if (c == '+') current++;
        else if (c == '-') current--;
        else unrecognized++;
    }

    int distance_needed = target - current;

    // To reach the target, the unrecognized '?' must sum up to distance_needed.
    // Let p be the number of '+' choices and m be the number of '-' choices.
    // p + m = unrecognized
    // p - m = distance_needed
    // Adding both equations: 2p = unrecognized + distance_needed -> p = (unrecognized + distance_needed) / 2
    
    int total_moves_pool = unrecognized + distance_needed;
    
    // Check if a valid arrangement of '+' and '-' is mathematically possible
    if (total_moves_pool < 0 || total_moves_pool % 2 != 0) {
        cout << fixed << setprecision(12) << 0.0 << "\n";
        return;
    }

    int required_plus = total_moves_pool / 2;

    if (required_plus > unrecognized) {
        cout << fixed << setprecision(12) << 0.0 << "\n";
        return;
    }

    // Ways to arrange 'required_plus' pluses in 'unrecognized' slots
    long long favorable_outcomes = nCr(unrecognized, required_plus);
    // Total sample space of binary choices (2^unrecognized)
    long long total_outcomes = 1LL << unrecognized; 

    double probability = (double)favorable_outcomes / total_outcomes;
    cout << fixed << setprecision(12) << probability << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}