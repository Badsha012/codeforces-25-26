#include <iostream>
#include <vector>

using namespace std;

void solve(int caseNum) {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    long long count = 0;

    if (k == 1) {
        // Case for 1 item
        for (int i = 0; i < n; i++) {
            if (prices[i] == b) count++;
        }
    } 
    else if (k == 2) {
        // Case for 2 items
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[i] + prices[j] == b) count++;
            }
        }
    } 
    else if (k == 3) {
        // Case for 3 items
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int l = j + 1; l < n; l++) {
                    if (prices[i] + prices[j] + prices[l] == b) count++;
                }
            }
        }
    }

    cout << "Case " << caseNum << ": " << count << endl;
}

int main() {
    int t;
    if (!(cin >> t)) return 0;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}