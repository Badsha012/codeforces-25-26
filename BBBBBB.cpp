#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> ones;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') ones.push_back(i);
        }
        if (ones.empty()) {
            cout << (n + 2) / 3 << '\n';
        } else {
            int ans = ones.size();
            // Prefix: zeros before the first '1'
            ans += (ones[0] + 1) / 3;
            // Suffix: zeros after the last '1'
            ans += (n - ones.back()) / 3;
            // Internal gaps between consecutive '1's
            for (size_t i = 0; i + 1 < ones.size(); ++i) {
                int gap = ones[i+1] - ones[i] - 1;
                ans += gap / 3;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}