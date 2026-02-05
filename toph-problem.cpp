#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;

    // We store conflicts as pairs of bit indices
    vector<pair<int, int>> conflicts;
    for (int i = 0; i < M; ++i) {
        char u, v;
        cin >> u >> v;
        // Convert 'A'-'Z' to 0-25
        conflicts.push_back({u - 'A', v - 'A'});
    }

    int max_cards = 0;

    // Iterate through all 2^N possible subsets using a bitmask
    // 1 << N is equivalent to 2^N
    for (int mask = 0; mask < (1 << N); ++mask) {
        bool safe = true;

        // Check if this subset contains any conflicting pairs
        for (auto& p : conflicts) {
            // If both bit 'u' and bit 'v' are set in the mask, it's a conflict
            if ((mask & (1 << p.first)) && (mask & (1 << p.second))) {
                safe = false;
                break;
            }
        }

        if (safe) {
            // __builtin_popcount is a fast way to count set bits (1s)
            int current_count = __builtin_popcount(mask);
            max_cards = max(max_cards, current_count);
        }
    }

    cout << max_cards << endl;

    return 0;
}