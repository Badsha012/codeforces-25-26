#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int x = 0, y = 0;
        int len = s.size();

        // count goals so far
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') {
                if (i % 2 == 0) x++; // Team X
                else y++;          // Team Y
            }
        }

        bool xTurn = (len % 2 == 0); // whose turn now
        int shotsX = 5 - (len + 1) / 2;
        int shotsY = 5 - (len / 2);

        auto winsIf = [&](int add) {
            int cx = x, cy = y;
            int rx = shotsX, ry = shotsY;

            if (xTurn) {
                cx += add;
                rx--;
            } else {
                cy += add;
                ry--;
            }

            // opponent max possible goals
            int maxX = cx + rx;
            int maxY = cy + ry;

            if (cx > maxY) return 1; // X surely wins
            if (cy > maxX) return -1; // Y surely wins
            return 0; // not decided
        };

        int scoreRes = winsIf(1);
        int missRes  = winsIf(0);

        if (scoreRes != 0 && missRes == 0)
            cout << 1 << "\n";
        else if (missRes != 0 && scoreRes == 0)
            cout << 0 << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}
