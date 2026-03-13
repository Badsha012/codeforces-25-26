#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    vector<int> a(12);
    for (int i = 0; i < 12; i++) {
        cin >> a[i];
    }

    // Base case: If 0 growth is required, 0 months are needed
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Sort in descending order to pick the most productive months first
    sort(a.rbegin(), a.rend());

    int current_growth = 0;
    int months_count = 0;

    for (int i = 0; i < 12; i++) {
        current_growth += a[i];
        months_count++;
        
        if (current_growth >= k) {
            cout << months_count << endl;
            return 0;
        }
    }

    // If we finished the loop and growth is still < k
    cout << -1 << endl;

    return 0;
}