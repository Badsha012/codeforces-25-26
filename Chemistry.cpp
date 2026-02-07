#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Step 1: Count character frequencies
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Step 2: Count how many characters appear an odd number of times
    int odd_count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            odd_count++;
        }
    }

    // Step 3: Check the condition
    // We can remove k characters. To form a palindrome, we need 
    // the remaining odd frequencies to be at most 1.
    // So, even if we use k removals to eliminate odd counts, 
    // we need: odd_count - k <= 1
    if (k >= odd_count - 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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