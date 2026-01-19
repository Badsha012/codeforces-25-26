#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double sum = 0;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        sum += x;
        cout << fixed << setprecision(10) << (sum / i) << "\n";
    }

    return 0;
}
