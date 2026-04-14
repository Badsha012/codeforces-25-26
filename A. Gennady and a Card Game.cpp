#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tableCard;
    cin >> tableCard;

    bool canPlay = false;
    for (int i = 0; i < 5; ++i) {
        string handCard;
        cin >> handCard;

        // Check if rank matches OR suit matches
        if (handCard[0] == tableCard[0] || handCard[1] == tableCard[1]) {
            canPlay = true;
        }
    }

    if (canPlay) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}