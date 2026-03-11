#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Function to compare two subarrays of S starting at idx1 and idx2
bool is_smaller(const vector<int>& S, int idx1, int idx2, int M) {
    for (int i = 0; i < M; ++i) {
        if (S[idx1 + i] < S[idx2 + i]) return true;
        if (S[idx1 + i] > S[idx2 + i]) return false;
    }
    return false; // They are equal
}

void solve(int caseNum) {
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (int i = 0; i < N; ++i) cin >> S[i];
    
    // We only need the frequency of elements in T
    map<int, int> targetFreq;
    for (int i = 0; i < M; ++i) {
        cin >> T[i];
        targetFreq[T[i]]++;
    }

    if (M > N) {
        cout << "Case " << caseNum << ": 0" << endl;
        return;
    }

    map<int, int> currentFreq;
    int matches = 0;
    int required = targetFreq.size();
    int bestIdx = -1;

    // Sliding Window
    for (int i = 0; i < N; ++i) {
        // Add current element
        int val = S[i];
        if (targetFreq.count(val)) {
            currentFreq[val]++;
            if (currentFreq[val] == targetFreq[val]) matches++;
            else if (currentFreq[val] == targetFreq[val] + 1) matches--;
        }

        // Remove element sliding out of window
        if (i >= M) {
            int outVal = S[i - M];
            if (targetFreq.count(outVal)) {
                if (currentFreq[outVal] == targetFreq[outVal]) matches--;
                currentFreq[outVal]--;
                if (currentFreq[outVal] == targetFreq[outVal]) matches++;
            }
        }

        // Check if window is an anagram
        if (matches == required) {
            int currentStart = i - M + 1;
            if (bestIdx == -1 || is_smaller(S, currentStart, bestIdx, M)) {
                bestIdx = currentStart;
            }
        }
    }

    cout << "Case " << caseNum << ": " << (bestIdx == -1 ? 0 : bestIdx + 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Ts;
    cin >> Ts;
    for (int i = 1; i <= Ts; ++i) {
        solve(i);
    }
    return 0;
}