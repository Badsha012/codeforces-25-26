#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    set<int> elements;
    bool has_duplicate = false;
    
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
      
        if (elements.count(val)) {
            has_duplicate = true;
        }
        elements.insert(val);
    }
    
   
    if (elements.size() == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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