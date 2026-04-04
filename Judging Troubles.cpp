#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Problem: Judging Troubles
 * Complexity: O(N * L), where N is number of submissions and L is max string length.
 */

int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Frequencies for DOMjudge results
    unordered_map<string, int> domjudge_counts;
    for (int i = 0; i < n; ++i) {
        string result;
        cin >> result;
        domjudge_counts[result]++;
    }

    // Frequencies for Kattis results
    unordered_map<string, int> kattis_counts;
    for (int i = 0; i < n; ++i) {
        string result;
        cin >> result;
        kattis_counts[result]++;
    }

    int total_consistent = 0;

    // Compare counts for each unique result found in DOMjudge
    for (auto const& [result, count] : domjudge_counts) {
        // If the same result exists in Kattis, take the minimum of the two counts
        if (kattis_counts.count(result)) {
            total_consistent += min(count, kattis_counts[result]);
        }
    }

    cout << total_consistent << endl;

    return 0;
}