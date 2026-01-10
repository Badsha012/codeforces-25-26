#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

// Function to precompute factorials up to 15
ll factorial[16];
void precompute() {
    factorial[0] = 1;
    for (int i = 1; i <= 15; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
}

// Function to calculate unique permutations of a string
ll getPermutationValue(const string& s) {
    int n = s.length();
    vector<int> counts(10, 0);
    for (char c : s) {
        counts[c - '0']++;
    }

    ll result = factorial[n];
    for (int i = 0; i <= 9; ++i) {
        if (counts[i] > 1) {
            result /= factorial[counts[i]];
        }
    }
    return result;
}

void solve() {
    string S, T;
    cin >> S >> T;

    if (getPermutationValue(S) == getPermutationValue(T)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int Q;
    if (!(cin >> Q)) return 0;
    while (Q--) {
        solve();
    }
    return 0;
}