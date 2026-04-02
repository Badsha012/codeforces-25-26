#include <iostream>

using namespace std;

int main() {
    int N, M;

    // Read the number of problems solved by the 1st team
    if (!(cin >> N)) return 0;
    
    // Read the number of problems solved by the 2nd team
    if (!(cin >> M)) return 0;

    // Compare the scores
    if (N > M) {
        // 1st team has more solved problems
        cout << "Champion" << endl;
        cout << "Runner up" << endl;
    } else {
        // 2nd team has more solved problems
        cout << "Runner up" << endl;
        cout << "Champion" << endl;
    }

    return 0;
}