#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;
    
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) cin >> xs[i];
    for (int i = 0; i < n; i++) cin >> ys[i];
    
    map<int, pair<int, int>> mp;
    mp[Ax] = {Ay, Ay};
    mp[Bx] = {By, By};
    
    for (int i = 0; i < n; i++) {
        int x = xs[i], y = ys[i];
        if (mp.find(x) == mp.end()) {
            mp[x] = {y, y};
        } else {
            mp[x].first = min(mp[x].first, y);
            mp[x].second = max(mp[x].second, y);
        }
    }
    
    vector<pair<int, pair<int, int>>> points;
    for (auto &[x, p] : mp) {
        points.push_back({x, p});
    }
    sort(points.begin(), points.end());
    
    int m = points.size();
    vector<ll> dpL(m), dpH(m);
    dpL[0] = dpH[0] = 0;
    int prevLow = points[0].second.first, prevHigh = points[0].second.second;
    
    for (int i = 1; i < m; i++) {
        int x = points[i].first;
        int low = points[i].second.first;
        int high = points[i].second.second;
        int dx = x - points[i-1].first;
        int dy = high - low;
        
        // to end at low
        ll costLL = dpL[i-1] + dx + min(abs(prevLow - high), abs(prevLow - low) + dy) + dy;
        ll costHL = dpH[i-1] + dx + min(abs(prevHigh - high), abs(prevHigh - low) + dy) + dy;
        dpL[i] = min(costLL, costHL);
        
        // to end at high
        ll costLH = dpL[i-1] + dx + min(abs(prevLow - low), abs(prevLow - high) + dy) + dy;
        ll costHH = dpH[i-1] + dx + min(abs(prevHigh - low), abs(prevHigh - high) + dy) + dy;
        dpH[i] = min(costLH, costHH);
        
        prevLow = low;
        prevHigh = high;
    }
    
    cout << min(dpL[m-1], dpH[m-1]) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}