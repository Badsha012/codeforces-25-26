#include <iostream>
#include <algorithm>

using namespace std;

// N is up to 1000, so a 1001x1001 matrix is safe.
// Using a global array initializes all values to false (0).
bool has_interacted[1005][1005];

int main() {
    // Optimize I/O for 100,000 operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;

        // Ensure u is always the smaller ID to handle symmetry (1,2 == 2,1)
        int first = min(u, v);
        int second = max(u, v);

        if (has_interacted[first][second]) {
            cout << "old\n";
        } else {
            cout << "new\n";
            // Mark this interaction as seen
            has_interacted[first][second] = true;
        }
    }

    return 0;
}