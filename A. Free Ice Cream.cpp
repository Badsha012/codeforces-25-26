#include <iostream>

using namespace std;

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x; // Use long long for the ice cream count
    if (!(cin >> n >> x)) return 0;

    int distressed_kids = 0;

    for (int i = 0; i < n; i++) {
        char type;
        long long d;
        cin >> type >> d;

        if (type == '+') {
            // Carrier arrives: add ice cream to the stock
            x += d;
        } else if (type == '-') {
            // Child arrives: check if we have enough
            if (x >= d) {
                x -= d;
            } else {
                // Not enough ice cream: child leaves in distress
                distressed_kids++;
            }
        }
    }

    // Output the remaining ice cream and the count of distressed kids
    cout << x << " " << distressed_kids << endl;

    return 0;
}