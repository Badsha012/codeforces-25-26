#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int cntA = 0, cntB = 0;

        for (char c : s) {
            if (c == 'A') cntA++;
            else cntB++;
        }

        if (cntA > cntB)
            cout << "A\n";
        else
            cout << "B\n";
    }

    return 0;
}
