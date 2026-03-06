#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();
    // dp[i] will store the number of pairs s[j] == s[j+1] for j < i
    vector<int> dp(n + 1, 0);

    // Build the prefix sum array
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (s[i] == s[i - 1]) {
            dp[i]++;
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        
        cout << dp[r - 1] - dp[l - 1] << "\n";
    }

    return 0;
}