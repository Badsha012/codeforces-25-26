#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    long long result = 1;
    for (int i = 0; i < x; i++) {
        result *= y;
    }

    cout << result << endl;
    return 0;
}
