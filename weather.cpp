#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;

    if (p >= 70) {
        cout << "Bad weather." << endl;
    }
    else if (p <= 30) {
        cout << "Good weather." << endl;
    }
    else {
        cout << "Confusing weather." << endl;
    }

    return 0;
}
