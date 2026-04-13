#include <iostream>
#include <string>

using namespace std;

void solve() {
    string A, B;
    if (!(cin >> A >> B)) return;

    // Get the last digit of each number
    int lastA = A.back() - '0';
    int lastB = B.back() - '0';

    // Parity of the sum (A + B)
    if ((lastA + lastB) % 2 == 0) {
        cout << "Black" << endl;
    } else {
        cout << "White" << endl;
    }
}

int main() {
    // Fast I/O for large string inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}