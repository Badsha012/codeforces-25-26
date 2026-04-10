#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    
    // Use getline to read the entire line including spaces
    if (getline(cin, s)) {
        // Iterate through each character of the string
        for (int i = 0; i < s.length(); i++) {
            // Only print the character if it is not a space
            if (s[i] != ' ') {
                cout << s[i];
            }
        }
        // Print a newline at the end
        cout << endl;
    }
    
    return 0;
}