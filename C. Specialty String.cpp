#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/**
 * Problem C: Specialty String
 * Logic: A string can be fully reduced to '*' if and only if it follows
 * a nested matching structure, similar to valid parentheses.
 */
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
       
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            // Otherwise, this character needs to wait for its future match
            st.push(c);
        }
    }

    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Speed up I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}