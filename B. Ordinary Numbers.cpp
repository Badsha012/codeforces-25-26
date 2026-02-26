#include <iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    
    int count = 0;
    
  
    for (int digit = 1; digit <= 9; ++digit) {
        long long current_ordinary = 0;
        
        for (int len = 1; len <= 9; ++len) {
            current_ordinary = current_ordinary * 10 + digit;
            
            
            if (current_ordinary <= n) {
                count++;
            } else {
            
                break;
            }
        }
    }
    
    cout << count << endl;
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