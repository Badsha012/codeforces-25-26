#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll round_up(ll x, ll y) {
    ll p = x;
    while (p & y) {
        int k = __builtin_ctzll(p & y);
        // Round up to next multiple of 2^(k+1) to clear bit k and all lower bits
        p = ((p >> (k + 1)) + 1) << (k + 1);
    }
    return p;
}

ll round_down(ll x, ll y) {
    ll p = x;
    while (p & y) {
        int k = __builtin_ctzll(p & y);
        // Clear bit k and all lower bits
        p &= ~((1LL << (k + 1)) - 1);
        // Set lower bits to 1 where y has 0 (to maximize p)
        ll mask = (1LL << k) - 1;
        p |= (~y) & mask;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> x >> y;
        
        ll p_up = round_up(x, y);
        ll cost_up_x = p_up - x;
        
        ll q_up = round_up(y, x);
        ll cost_up_y = q_up - y;
        
        ll p_down = round_down(x, y);
        ll cost_down_x = x - p_down;
        
        ll q_down = round_down(y, x);
        ll cost_down_y = y - q_down;
        
        ll min_cost = min({cost_up_x, cost_up_y, cost_down_x, cost_down_y});
        
        if (min_cost == cost_up_x) {
            cout << p_up << " " << y << "\n";
        } else if (min_cost == cost_up_y) {
            cout << x << " " << q_up << "\n";
        } else if (min_cost == cost_down_x) {
            cout << p_down << " " << y << "\n";
        } else {
            cout << x << " " << q_down << "\n";
        }
    }
    return 0;
}