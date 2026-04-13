#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    int consecutive_count = 0;
    int last_merged = -1;
    bool won = false;

    for (int i = 0; i < N; ++i) {
        int d1, d2;
        cin >> d1 >> d2;
        
        // Form the merged number (e.g., 5 and 6 becomes 56)
        int current_merged = d1 * 10 + d2;

        if (current_merged == last_merged) {
            consecutive_count++;
        } else {
            consecutive_count = 1;
        }

        // Check if we hit the win condition
        if (consecutive_count >= 3) {
            won = true;
        }

        last_merged = current_merged;
    }

    if (won) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}