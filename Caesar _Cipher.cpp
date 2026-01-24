#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // ignore newline

    string s;
    getline(cin, s);

    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - N + 26) % 26 + 'a';
        }
        // spaces remain unchanged
    }

    cout << s << endl;
    return 0;
}
