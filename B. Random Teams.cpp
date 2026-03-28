#include <iostream>

using namespace std;

/**
 * Helper function to calculate xC2: x * (x - 1) / 2
 */
long long countPairs(long long x) {
    if (x < 2) return 0;
    return x * (x - 1) / 2;
}

int main() {
    // Optimization for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    if (!(cin >> n >> m)) return 0;

    // --- Calculate k_max ---
    // One team gets everyone except the 1 person required for each other team
    long long max_team_size = n - (m - 1);
    long long k_max = countPairs(max_team_size);

    // --- Calculate k_min ---
    // Distribute participants as evenly as possible
    long long base_size = n / m;
    long long extra_people = n % m;
    
    // extra_people teams will have (base_size + 1) members
    // (m - extra_people) teams will have (base_size) members
    long long k_min = (extra_people * countPairs(base_size + 1)) + 
                     ((m - extra_people) * countPairs(base_size));

    cout << k_min << " " << k_max << endl;

    return 0;
}