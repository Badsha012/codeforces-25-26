#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void solve() {
    long long N, K;
    long long D, X, Y;
    
    if (!(cin >> N >> K >> D >> X >> Y)) return;

    double time;
    
    // If we have more boats than swimmers, everyone just takes a boat.
    if (K >= N) {
        time = (double)D / Y;
    } else {
        // Use the derived formula for shared boat usage
        double numerator = (double)N * D;
        double denominator = (double)K * Y + (double)(N - K) * X;
        time = numerator / denominator;
    }

    cout << fixed << setprecision(10) << time << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}