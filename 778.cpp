#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(const vector<int>& idx_a, const vector<int>& idx_b, const vector<ll>& vals, ll k) {
    int m = vals.size();
    vector<int> comp(m, -1);
    set<int> unvisited;
    for (int i = 0; i < m; ++i) unvisited.insert(i);
    
    int comp_cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (comp[i] != -1) continue;
        
        queue<int> q;
        q.push(i);
        comp[i] = comp_cnt;
        unvisited.erase(i);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ll v_u = vals[u];
            
            // Left neighbors: indices with vals < v_u - k
            ll left_thresh = v_u - k;
            int idx_left = lower_bound(vals.begin(), vals.end(), left_thresh) - vals.begin();
            auto it_end = unvisited.lower_bound(idx_left);
            vector<int> to_add;
            for (auto it = unvisited.begin(); it != it_end; ) {
                int v = *it;
                to_add.push_back(v);
                it = unvisited.erase(it);
            }
            for (int v : to_add) {
                comp[v] = comp_cnt;
                q.push(v);
            }
            
            // Right neighbors: indices with vals > v_u + k
            ll right_thresh = v_u + k;
            int idx_right = upper_bound(vals.begin(), vals.end(), right_thresh) - vals.begin();
            auto it_start = unvisited.lower_bound(idx_right);
            to_add.clear();
            for (auto it = it_start; it != unvisited.end(); ) {
                int v = *it;
                to_add.push_back(v);
                it = unvisited.erase(it);
            }
            for (int v : to_add) {
                comp[v] = comp_cnt;
                q.push(v);
            }
        }
        comp_cnt++;
    }
    
    for (size_t i = 0; i < idx_a.size(); ++i) {
        if (comp[idx_a[i]] != comp[idx_b[i]]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<ll> b = a;
        sort(b.begin(), b.end());
        
        if (a == b) {
            cout << -1 << '\n';
            continue;
        }
        
        // Coordinate compression
        vector<ll> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        
        vector<int> idx_a(n), idx_b(n);
        for (int i = 0; i < n; ++i) {
            idx_a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
            idx_b[i] = lower_bound(vals.begin(), vals.end(), b[i]) - vals.begin();
        }
        
        ll lo = 1, hi = 1e9 + 1;
        ll ans = 1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (check(idx_a, idx_b, vals, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}