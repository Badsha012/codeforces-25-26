#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long ans = N * (N + 1) / 2 + 1;
    cout << ans << '\n';

    return 0;
}
