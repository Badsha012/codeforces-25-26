#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    
    
    int depth = 0;
    bool found = false;
    vector<int> siblings(n + 1, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
            st.push(i);
        } else {
            int open_idx = st.top();
            st.pop();
            depth--;
           
            if (st.size() > 0) {
                siblings[st.size()]++;
            }
        }
    }



    bool can_better = false;
    int current_siblings = 0;
    stack<int> count_st;
    count_st.push(0);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            count_st.push(0);
        } else {
            int kids = count_st.top();
            count_st.pop();
            if (kids > 0) {
          
                can_better = true;
            }
            count_st.top()++;
        }
    }

    
    int atoms = 0;
    int balance = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') balance++;
        else balance--;
        if(balance == 0) atoms++;
    }

    if (can_better) {
        cout << n - 2 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}