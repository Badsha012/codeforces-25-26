#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        vector<pair<int,int>> circles(N);
        for (int i = 0; i < N; i++) {
            cin >> circles[i].first >> circles[i].second;
        }

        long long maxDistSquared = 0; // use long long to avoid overflow
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                long long dx = circles[i].first - circles[j].first;
                long long dy = circles[i].second - circles[j].second;
                long long distSquared = dx*dx + dy*dy;
                maxDistSquared = max(maxDistSquared, distSquared);
            }
        }

        cout << "Case " << t << ": " << maxDistSquared << endl;
    }

    return 0;
}
