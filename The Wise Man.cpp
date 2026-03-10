#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/**
 * Problem: Miracle Grid (Magic Square Verification)
 * Goal: Check if all rows, columns, and diagonals sum to the same value.
 */

bool is_magic_square(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(cin >> grid[i][j])) return false;
        }
    }

    // Calculate the target sum from the first row
    long long target_sum = 0;
    for (int j = 0; j < n; j++) target_sum += grid[0][j];

    // Check Rows
    for (int i = 1; i < n; i++) {
        long long current_row_sum = 0;
        for (int j = 0; j < n; j++) current_row_sum += grid[i][j];
        if (current_row_sum != target_sum) return false;
    }

    // Check Columns
    for (int j = 0; j < n; j++) {
        long long current_col_sum = 0;
        for (int i = 0; i < n; i++) current_col_sum += grid[i][j];
        if (current_col_sum != target_sum) return false;
    }

    // Check Main Diagonal (top-left to bottom-right)
    long long diag1_sum = 0;
    for (int i = 0; i < n; i++) diag1_sum += grid[i][i];
    if (diag1_sum != target_sum) return false;

    // Check Anti-Diagonal (top-right to bottom-left)
    long long diag2_sum = 0;
    for (int i = 0; i < n; i++) diag2_sum += grid[i][n - 1 - i];
    if (diag2_sum != target_sum) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (is_magic_square(n)) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}