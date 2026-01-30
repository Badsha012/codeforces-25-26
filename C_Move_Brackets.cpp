#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int balance = 0;
    int moves = 0;

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else {
            balance--;
        }

        // If balance is negative, we have an unmatched ')'
        // We "move" this bracket, so it no longer affects the current balance
        if (balance < 0) {
            moves++;
            balance = 0; 
        }
    }

    cout << moves << endl;
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