#include <iostream>
#include <string>

using namespace std;

/**
 * Problem: A. Extremely Round
 * Strategy: Each magnitude (1, 10, 100...) has exactly 9 extremely round numbers.
 * The answer is 9 * (number of digits - 1) + (the first digit of n).
 */

void solve() {
    string n_str;
    cin >> n_str;
    
    // Number of full sets of 9 (e.g., if n is 3 digits, we have full sets for 1 and 2 digits)
    int full_sets = n_str.length() - 1;
    
    // The first digit tells us how many extremely round numbers exist in the current magnitude
    int leading_digit = n_str[0] - '0';
    
    int result = (full_sets * 9) + leading_digit;
    
    cout << result << "\n";
}

int main() {
    // Optimize I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}