#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int total_twos = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 2) {
            total_twos++;
        }
    }

    
    if (total_twos % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    
    if (total_twos == 0) {
        cout << 1 << endl;
        return;
    }

    int current_twos = 0;
    int target = total_twos / 2;

    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 2) {
            current_twos++;
        }
        if (current_twos == target) {
            cout << i + 1 << endl; 
            return;
        }
    }

    cout << -1 << endl;
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