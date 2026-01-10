#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, k;
    cin >> n >> x >> k;

    vector<long long> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    
    int idx = upper_bound(A.begin(), A.end(), x) - A.begin();

    
    if (idx + k - 1 < n) {
        cout << A[idx + k - 1] << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
