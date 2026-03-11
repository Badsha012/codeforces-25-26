#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Community {
    int min_id;
    int size;
};

// DSU structure to manage communities
struct DSU {
    vector<int> parent;
    vector<int> sz;
    vector<int> min_val;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
        min_val.resize(n + 1);
        iota(min_val.begin(), min_val.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            min_val[root_i] = min(min_val[root_i], min_val[root_j]);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    DSU dsu(N);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    vector<Community> communities;
    for (int i = 1; i <= N; ++i) {
        if (dsu.parent[i] == i) {
            communities.push_back({dsu.min_val[i], dsu.sz[i]});
        }
    }

    // Sort by cheapest entry user ID
    sort(communities.begin(), communities.end(), [](const Community& a, const Community& b) {
        return a.min_id < b.min_id;
    });

    long long total_cost = 0;
    int users_reached = 0;

    for (const auto& com : communities) {
        if (users_reached >= K) break;
        total_cost += com.min_id;
        users_reached += com.size;
    }

    cout << total_cost << endl;

    return 0;
}