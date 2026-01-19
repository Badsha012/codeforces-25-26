#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int rem = Y % X;
    if (rem == 0)
        cout << 0 << "\n";
    else
        cout << X - rem << "\n";

    return 0;
}
