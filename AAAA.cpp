#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // The construction [2, 3, ..., n, 1] works because:
    // For i from 1 to n-2: |p[i] - p[i+1]| = 1. 
    // Wait, the condition is |p[i] - p[i+1]| is divisible by i.
    // If |p[i] - p[i+1]| = 1, it is only divisible by i if i = 1.
    // Let's re-examine the example n=3: 2 3 1.
    // i=1: |2-3|=1 (div by 1) - OK
    // i=2: |3-1|=2 (div by 2) - OK
    
    // For n=4:
    // We need |p3 - p4| div by 3. Only {1, 4} works.
    // So p3=4, p4=1.
    // We need |p2 - p3| div by 2. |p2 - 4| div by 2. p2 must be 2.
    // Remaining is 3. So: 3 2 4 1.
    // Check 3 2 4 1:
    // i=1: |3-2|=1 (div by 1) - OK
    // i=2: |2-4|=2 (div by 2) - OK
    // i=3: |4-1|=3 (div by 3) - OK
    
    // General pattern: 
    // Start with all numbers in order: 1, 2, 3, ..., n
    // The example n=3 (2 3 1) is a left cyclic shift of (1 2 3).
    // The n=4 (3 2 4 1) is different. 
    // Let's use the simplest logic: [2, 3, ..., n, 1] ONLY works for n=2,3.
    // A universal construction: [p_1, p_2, ..., p_n]
    // Let p_n = 1. 
    // For i = n-1 down to 1:
    // p_i is the smallest available number such that |p_i - p_{i+1}| % i == 0.
    
    vector<int> p(n + 1);
    vector<bool> used(n + 1, false);
    p[n] = 1;
    used[1] = true;
    
    for (int i = n - 1; i >= 1; --i) {
        for (int val = 1; val <= n; ++val) {
            if (!used[val] && abs(val - p[i + 1]) % i == 0) {
                p[i] = val;
                used[val] = true;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << (i == n ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}