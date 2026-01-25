#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<bool> exists(n + 1, false);
    vector<int> unique_elements;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!exists[a[i]]) {
            exists[a[i]] = true;
            unique_elements.push_back(a[i]);
        }
    }
    // Sorting helps keep the multiplication bail-out efficient
    sort(unique_elements.begin(), unique_elements.end());

    // dist[i] stores the min elements to get product i
    // Initialize with -1 (unreachable)
    vector<int> dist(n + 1, -1);
    queue<int> q;

    // Base cases: any element present in 'a' can be reached in 1 step
    for (int x : unique_elements) {
        dist[x] = 1;
        q.push(x);
    }

    // Standard BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int x : unique_elements) {
            // Using long long to prevent overflow during multiplication check
            long long next_val = (long long)u * x;
            
            if (next_val > n) break; // Optimization: unique_elements is sorted
            
            if (dist[(int)next_val] == -1) {
                dist[(int)next_val] = dist[u] + 1;
                q.push((int)next_val);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << "\n";
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