#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // bishop moves diagonally in one move
        if (abs(r1 - r2) == abs(c1 - c2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
