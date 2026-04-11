#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    
    vector<int> a(k);
    int max_val = 0;
    int max_idx = -1;

    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (a[i] > max_val) {
            max_val = a[i];
            max_idx = i;
        }
    }

    long long operations = 0;
    for (int i = 0; i < k; i++) {
        // Skip the largest piece; we merge everything into it.
        if (i == max_idx) continue;

        // Cost to break into 1s: a[i] - 1
        // Cost to merge those 1s: a[i]
        operations += (2LL * a[i] - 1);
    }

    cout << operations << endl;
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