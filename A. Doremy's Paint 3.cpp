#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        counts[x]++;
    }

    // Condition 1: If only one distinct number, it's always good (e.g., [5, 5, 5])
    if (counts.size() == 1) {
        cout << "Yes" << endl;
    } 
    // Condition 2: If exactly two distinct numbers
    else if (counts.size() == 2) {
        vector<int> f;
        for (auto const& [val, freq] : counts) {
            f.push_back(freq);
        }
        
        // The difference in frequency cannot be more than 1
        // This covers both even and odd n logic
        if (abs(f[0] - f[1]) <= 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } 
    // Condition 3: More than 2 distinct numbers
    else {
        cout << "No" << endl;
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