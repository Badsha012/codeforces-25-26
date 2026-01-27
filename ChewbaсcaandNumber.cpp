#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;

    for (int i = 0; i < x.length(); i++) {
        int digit = x[i] - '0';
        int inverted = 9 - digit;

        // Check if inverting makes the digit smaller
        if (inverted < digit) {
            // Special case: Don't allow the first digit to become '0'
            if (i == 0 && inverted == 0) {
                continue; 
            }
            x[i] = inverted + '0';
        }
    }

    cout << x << endl;

    return 0;
}