#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int current_whites = 0;
    
    // 1. Calculate 'W' count for the first window of size k
    for (int i = 0; i < k; i++) {
        if (s[i] == 'W') {
            current_whites++;
        }
    }

    int min_whites = current_whites;

    // 2. Slide the window from index 1 to n-k
    for (int i = k; i < n; i++) {
        // Add the new element entering from the right
        if (s[i] == 'W') {
            current_whites++;
        }
        // Remove the element leaving from the left
        if (s[i - k] == 'W') {
            current_whites--;
        }
        
        // Update the minimum
        min_whites = min(min_whites, current_whites);
    }

    cout << min_whites << endl;
}

int main() {
    // Optimize I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}