#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total_dishes = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_dishes += a[i];
    }

    set<int> winners;

    
    for (int start_player = 0; start_player < n; start_player++) {
       
        int winner_idx = (start_player + (int)((total_dishes - 1) % n)) % n;
        winners.insert(winner_idx);
    }

    cout << winners.size() << endl;
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