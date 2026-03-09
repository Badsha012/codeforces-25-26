#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int cat[MAXN];
int n, m, valid_restaurants = 0;

void dfs(int u, int p, int consecutive_cats, int max_seen) {
    // Update consecutive cats count
    if (cat[u]) {
        consecutive_cats++;
    } else {
        consecutive_cats = 0;
    }

    // Keep track of the highest consecutive count seen on this path
    max_seen = max(max_seen, consecutive_cats);

    // If we've already failed the cat requirement, stop exploring this branch
    if (max_seen > m) {
        return;
    }

    bool is_leaf = true;
    for (int v : adj[u]) {
        if (v != p) {
            is_leaf = false;
            dfs(v, u, consecutive_cats, max_seen);
        }
    }

    // If it's a leaf (and not the root in a single-node tree case) 
    // and we haven't returned early, it's a valid restaurant.
    if (is_leaf && u != 0) { 
        valid_restaurants++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> cat[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Start DFS from root (1), with no parent (0), 
    // 0 current consecutive cats, and 0 max seen.
    dfs(1, 0, 0, 0);

    cout << valid_restaurants << endl;

    return 0;
}