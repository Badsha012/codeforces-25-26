#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    vector<int> N(T);
    int maxN = 0;
    for (int i = 0; i < T; i++) {
        cin >> N[i];
        maxN = max(maxN, N[i]);
    }

    // visited positions (limit given in problem)
    const int LIM = 600000;
    vector<bool> visited(LIM + 1, false);
    vector<int> pos(maxN + 1);

    int cur = 0;
    visited[0] = true;

    for (int k = 1; k <= maxN; k++) {
        int target = cur - k;
        if (target > 0 && !visited[target]) {
            cur = target;
        } else {
            cur = cur + k;
        }
        visited[cur] = true;
        pos[k] = cur;
    }

    for (int i = 0; i < T; i++) {
        cout << pos[N[i]] << '\n';
    }

    return 0;
}
