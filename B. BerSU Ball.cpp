#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    
    // Input boys
    cin >> n;
    vector<int> boys(n);
    for (int i = 0; i < n; i++) cin >> boys[i];
    
    // Input girls
    cin >> m;
    vector<int> girls(m);
    for (int j = 0; j < m; j++) cin >> girls[j];

    // Step 1: Sort both arrays
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int pairs = 0;
    int i = 0; // Pointer for boys
    int j = 0; // Pointer for girls

    // Step 2: Two-pointer greedy matching
    while (i < n && j < m) {
        if (abs(boys[i] - girls[j]) <= 1) {
            // Valid pair found
            pairs++;
            i++;
            j++;
        } else if (boys[i] < girls[j]) {
            // Boy is too low skill, try next boy
            i++;
        } else {
            // Girl is too low skill, try next girl
            j++;
        }
    }

    // Step 3: Output the result
    cout << pairs << endl;

    return 0;
}