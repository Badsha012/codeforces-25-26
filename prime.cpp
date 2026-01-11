#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long original = N;
    vector<pair<long long, long long>> factors;

    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            long long count = 0;
            while (N % i == 0) {
                N /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }

    // If remaining N is a prime
    if (N > 1) {
        factors.push_back({N, 1});
    }

    // Output
    cout << original << " = ";
    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i].first << " ^ " << factors[i].second;
        if (i + 1 < factors.size()) cout << " * ";
    }
    cout << "\n";

    return 0;
}
