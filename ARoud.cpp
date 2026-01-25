#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    
    vector<int> a(n);
    long long current_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        current_sum += a[i];
    }

    if (s >= current_sum && (s - current_sum) % x == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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