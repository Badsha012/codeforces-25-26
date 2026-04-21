#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Store reading capacity for Monday (index 0) through Sunday (index 6)
    vector<int> days(7);
    for (int i = 0; i < 7; i++) {
        cin >> days[i];
    }

    int current_day = 0;
    while (n > 0) {
        // Subtract pages read on the current day
        n -= days[current_day];

        // If n <= 0, Petr finished the book today
        if (n <= 0) {
            // Output current_day + 1 because the problem uses 1-based indexing
            cout << current_day + 1 << endl;
            break;
        }

        // Move to the next day, wrapping around from Sunday (6) to Monday (0)
        current_day = (current_day + 1) % 7;
    }

    return 0;
}