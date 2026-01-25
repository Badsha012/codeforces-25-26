#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // 1. Sort swords in descending order.
    // a[0] is the strongest, a[n-1] is the weakest.
    sort(a.begin(), a.end(), greater<ll>());

    ll max_score = 0;
    ll required_swords = 0;

    // 2. Iterate through levels k (1 to n)
    for (int k = 1; k <= n; k++) {
        // required_swords is the sum of b[0...k-1]
        required_swords += b[k-1];

        // 3. Check if we have enough total swords in the game
        // to even attempt completing k levels.
        if (required_swords <= n) {
            // The difficulty x can be at most the strength of the 
            // (required_swords)-th strongest sword.
            // Indexing is 0-based, so we use [required_swords - 1].
            ll x = a[required_swords - 1];
            max_score = max(max_score, x * k);
        } else {
            // If we need more than n swords, we can't complete more levels.
            break;
        }
    }

    cout << max_score << "\n";
}

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}