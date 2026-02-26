#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int sum_efficiency = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        int a;
        cin >> a;
        sum_efficiency += a;
    }
    
    
    cout << -sum_efficiency << endl;
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