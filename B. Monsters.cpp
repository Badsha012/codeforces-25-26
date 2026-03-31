#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Monster {
    int id;
    int rem;
};

// Custom comparator to sort by remainder descending, then index ascending
bool compareMonsters(const Monster& a, const Monster& b) {
    if (a.rem != b.rem) {
        return a.rem > b.rem;
    }
    return a.id < b.id;
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;

    vector<Monster> monsters(n);
    for (int i = 0; i < n; i++) {
        int health;
        cin >> health;
        
        // Calculate effective health
        int r = health % k;
        if (r == 0) r = k; // Multiples of k die first in the final cycles
        
        monsters[i] = {i + 1, r};
    }

    // Sort based on our logic
    sort(monsters.begin(), monsters.end(), compareMonsters);

    // Print the indices
    for (int i = 0; i < n; i++) {
        cout << monsters[i].id << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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