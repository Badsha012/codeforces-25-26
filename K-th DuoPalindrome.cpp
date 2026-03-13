#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

// Standard factorial for small N (max length of Q is small here)
ll factorial(int n) {
    ll res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

// Count permutations of a multiset
ll countPermutations(map<char, int>& freq, int remainingLen) {
    ll total = factorial(remainingLen);
    for (auto const& [ch, count] : freq) {
        total /= factorial(count);
    }
    return total;
}

int main() {
    string s;
    ll K;
    if (!(cin >> s >> K)) return 0;

    map<char, int> fullFreq;
    for (char c : s) fullFreq[c]++;

    map<char, int> qFreq;
    char middle = '\0';
    int qLen = s.length() / 4;

    for (auto const& [ch, count] : fullFreq) {
        if (count == 4) {
            qFreq[ch] = 1;
        } else if (count == 2) {
            middle = ch;
        }
    }

    string Q = "";
    int currentQLen = qLen;

    // Construct Q lexicographically
    for (int i = 0; i < qLen; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (qFreq[c] > 0) {
                qFreq[c]--;
                ll cnt = countPermutations(qFreq, currentQLen - 1);
                if (K <= cnt) {
                    Q += c;
                    currentQLen--;
                    goto next_pos;
                } else {
                    K -= cnt;
                    qFreq[c]++;
                }
            }
        }
        next_pos:;
    }

    string half = Q;
    string revQ = Q;
    reverse(revQ.begin(), revQ.end());
    if (middle != '\0') half += middle;
    half += revQ;

    cout << half << half << endl;

    return 0;
}