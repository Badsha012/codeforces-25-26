#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        
        vector<int> best(n+2);
        best[n] = max(a[n], b[n]);
        for (int i = n-1; i >= 1; i--) {
            best[i] = max({a[i], b[i], best[i+1]});
        }
        
        vector<long long> prefix(n+1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + best[i];
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << prefix[r] - prefix[l-1] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}