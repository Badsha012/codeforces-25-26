#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(int caseNum) {
    int R, C;
    cin >> R >> C;
    vector<string> grid(R);
    for (int i = 0; i < R; ++i) {
        cin >> grid[i];
    }

    string smallest = "";

    // Helper function to update the smallest string found so far
    auto updateSmallest = [&](string s) {
        if (s.length() < 2) return;
        if (smallest == "" || s < smallest) {
            smallest = s;
        }
    };

    // 1. Horizontal Scan
    for (int i = 0; i < R; ++i) {
        string current = "";
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == 'X') {
                updateSmallest(current);
                current = "";
            } else {
                current += grid[i][j];
            }
        }
        updateSmallest(current);
    }

    // 2. Vertical Scan
    for (int j = 0; j < C; ++j) {
        string current = "";
        for (int i = 0; i < R; ++i) {
            if (grid[i][j] == 'X') {
                updateSmallest(current);
                current = "";
            } else {
                current += grid[i][j];
            }
        }
        updateSmallest(current);
    }

    cout << "Case " << caseNum << ": " << smallest << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
    return 0;
}