#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    string decrypted = "";
    int i = 0;
    
    while (i < n) {
        char current_char = s[i];
        decrypted += current_char; // The start of a block is always part of the original string
        
        // Advance to find the matching closing character
        int j = i + 1;
        while (j < n && s[j] != current_char) {
            j++;
        }
        
        // Move the pointer 'i' to the character right after the closing match
        i = j + 1;
    }
    
    cout << decrypted << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}