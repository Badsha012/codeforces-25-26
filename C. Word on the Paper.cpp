#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    string word = "";
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char c;
            cin >> c;
            // If the character is a lowercase letter, add it to our word
            if (c != '.') {
                word += c;
            }
        }
    }
    cout << word << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}