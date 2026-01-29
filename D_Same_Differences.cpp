#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // We use a map to store the frequency of (a[i] - i)
    map<int, long long> counts;
    long long pairs = 0;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        
        // The condition aj - ai = j - i is equivalent to aj - j = ai - i
        // Let x = a[i] - i
        int x = val - i;
        
        // If we have seen this value 'x' before, every previous occurrence 
        // forms a valid pair with the current index.
        pairs += counts[x];
        
        // Increment the count for this value
        counts[x]++;
    }

    cout << pairs << endl;
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