#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; 1LL * i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;

    if (N == 2) {
        cout << "Yes\n";
    } else if (isPrime(N + 2)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
