#include <iostream>

using namespace std;

int main() {
    long long n;
    if (!(cin >> n)) return 0;

    // Special case for n = 0
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    // Determine position in the cycle {8, 4, 2, 6}
    int remainder = n % 4;

    if (remainder == 1) {
        cout << 8 << endl;
    } else if (remainder == 2) {
        cout << 4 << endl;
    } else if (remainder == 3) {
        cout << 2 << endl;
    } else if (remainder == 0) {
        cout << 6 << endl;
    }

    return 0;
}