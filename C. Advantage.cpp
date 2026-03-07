#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<long long> s(n);
    vector<long long> sorted_s(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        sorted_s[i] = s[i];
    }
    
    // Sort the copy to easily find the two largest values
    sort(sorted_s.begin(), sorted_s.end());
    
    long long max1 = sorted_s[n - 1];
    long long max2 = sorted_s[n - 2];
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == max1) {
            // If this is the strongest person, subtract the second strongest
            cout << s[i] - max2 << " ";
        } else {
            // Otherwise, subtract the strongest
            cout << s[i] - max1 << " ";
        }
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}