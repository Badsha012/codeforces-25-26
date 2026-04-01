#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    char col = s[0]; // The letter (a-h)
    char row = s[1]; // The digit (1-8)

    // 1. Print all moves in the same column (Vertical moves)
    // We iterate from row '1' to '8'
    for (char r = '1'; r <= '8'; ++r) {
        if (r != row) {
            cout << col << r << "\n";
        }
    }

    // 2. Print all moves in the same row (Horizontal moves)
    // We iterate from column 'a' to 'h'
    for (char c = 'a'; c <= 'h'; ++c) {
        if (c != col) {
            cout << c << row << "\n";
        }
    }
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}