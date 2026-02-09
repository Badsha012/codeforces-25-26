#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int days = 0;
    int socks = n;

    while (socks > 0) {
        days++;    // A day passes
        socks--;   // He uses one pair

        // If it's a replenishment day, add a pair
        if (days % m == 0) {
            socks++;
        }
    }

    cout << days << endl;

    return 0;
}