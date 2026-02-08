#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to solve each test case
void solve() {
    int n, k;
    cin >> n >> k;

    // columns[i] will store a bitmask of characters present in the i-th column
    // bit 0 = 'a', bit 1 = 'b', ..., bit 25 = 'z'
    vector<int> columns(n, 0);
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            columns[j] |= (1 << (s[j] - 'a'));
        }
    }

    // Find all divisors of n and sort them to check smallest first
    vector<int> divisors;
    for (int d = 1; d * d <= n; ++d) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n) divisors.push_back(n / d);
        }
    }
    sort(divisors.begin(), divisors.end());

    for (int d : divisors) {
        string res = "";
        bool possible = true;

        for (int j = 0; j < d; ++j) {
            int common_chars = (1 << 26) - 1; // Start with all characters possible
            for (int i = j; i < n; i += d) {
                common_chars &= columns[i];
            }

            if (common_chars == 0) {
                possible = false;
                break;
            } else {
                // Pick the first available common character
                for (int c = 0; c < 26; ++c) {
                    if ((common_chars >> c) & 1) {
                        res += (char)('a' + c);
                        break;
                    }
                }
            }
        }

        if (possible) {
            // Output the repeating unit t expanded to length n
            for (int i = 0; i < n / d; ++i) {
                cout << res;
            }
            cout << "\n";
            return;
        }
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