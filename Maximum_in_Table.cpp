#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 1;
    int k = n - 1;

    // Compute C(2n-2, n-1)
    for (int i = 1; i <= k; i++) {
        result = result * (n - 1 + i) / i;
    }

    cout << result << endl;
    return 0;
}
