#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    while (N--) {
        string S, T;
        cin >> S >> T;

        int i = 0, j = 0;
        bool ok = true;

        while (i < S.size() && j < T.size()) {
            if (S[i] != T[j]) {
                ok = false;
                break;
            }

            char c = S[i];
            int cntS = 0, cntT = 0;

            // count block in S
            while (i < S.size() && S[i] == c) {
                cntS++;
                i++;
            }

            // count block in T
            while (j < T.size() && T[j] == c) {
                cntT++;
                j++;
            }

            if (cntT < cntS) {
                ok = false;
                break;
            }
        }

        // both must finish together
        if (i != S.size() || j != T.size()) {
            ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
