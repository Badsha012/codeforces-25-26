#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pref(n), suff(n);
    set<char> distinct_chars;

    // Fill prefix array: number of distinct chars from 0 to i
    for (int i = 0; i < n; i++) {
        distinct_chars.insert(s[i]);
        pref[i] = distinct_chars.size();
    }

    distinct_chars.clear();

    // Fill suffix array: number of distinct chars from i to n-1
    for (int i = n - 1; i >= 0; i--) {
        distinct_chars.insert(s[i]);
        suff[i] = distinct_chars.size();
    }

    int max_f = 0;
    // Try splitting after index i (string a is s[0...i], string b is s[i+1...n-1])
    for (int i = 0; i < n - 1; i++) {
        max_f = max(max_f, pref[i] + suff[i + 1]);
    }

    cout << max_f << "\n";
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}