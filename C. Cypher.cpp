#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    // final_digits stores the state of the wheels after moves
    vector<int> final_digits(n);
    for (int i = 0; i < n; ++i) {
        cin >> final_digits[i];
    }

    for (int i = 0; i < n; ++i) {
        int num_moves;
        string moves;
        cin >> num_moves >> moves;

        int current_digit = final_digits[i];
        for (char move : moves) {
            if (move == 'U') {
                // Reverse an Up move by going Down
                current_digit--;
                if (current_digit < 0) current_digit = 9;
            } else if (move == 'D') {
                // Reverse a Down move by going Up
                current_digit++;
                if (current_digit > 9) current_digit = 0;
            }
        }
        cout << current_digit << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    // Speed up I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}