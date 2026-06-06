#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the array to easily pair the maximum and minimum elements
    sort(a.begin(), a.end());
    
    int max_cost = 0;
    int left = 0;
    int right = n - 1;
    
    // Use two pointers to pair elements from both ends
    while (left < right) {
        max_cost += (a[right] - a[left]);
        left++;
        right--;
    }
    
    cout << max_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
