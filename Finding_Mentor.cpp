#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    stack<int> st;  // stores indices
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        // Remove all elements <= current score
        while (!st.empty() && S[st.top()] <= S[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top() + 1; // 1-based index

        st.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
