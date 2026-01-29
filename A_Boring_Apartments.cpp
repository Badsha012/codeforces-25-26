#include <iostream>
#include <string>

using namespace std;

void solve() {
    string x;
    cin >> x;

    // Get the digit used (convert char to int)
    int digit = x[0] - '0';
    // Get the length of the apartment number
    int len = x.length();

    // 1. Calculate digits from previous full groups (1 to digit-1)
    // Each full group has 10 digits (1+2+3+4)
    int total = (digit - 1) * 10;

    // 2. Add digits from the current group up to the length of x
    // If len=1: +1
    // If len=2: +1+2 = 3
    // If len=3: +1+2+3 = 6
    // If len=4: +1+2+3+4 = 10
    for (int i = 1; i <= len; i++) {
        total += i;
    }

    cout << total << endl;
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