#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    // Read the armies of the first m players
    vector<int> players(m);
    for (int i = 0; i < m; ++i) {
        cin >> players[i];
    }

    // Fedor is the (m + 1)-th player
    int fedor;
    cin >> fedor;

    int friends_count = 0;

    // Check each player against Fedor
    for (int i = 0; i < m; ++i) {
        // XOR highlights the differing bits
        int diff = players[i] ^ fedor;
        
        // __builtin_popcount counts the number of set bits (1s) efficiently
        if (__builtin_popcount(diff) <= k) {
            friends_count++;
        }
    }

    cout << friends_count << "\n";

    return 0;
}