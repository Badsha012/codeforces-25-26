#include <iostream>

using namespace std;

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        // If n is even, Mahmoud can take the whole number at once and win.
        // If n is odd, Ehab will always have the advantage.
        if (n % 2 == 0) {
            cout << "Mahmoud" << endl;
        } else {
            cout << "Ehab" << endl;
        }
    }

    return 0;
}