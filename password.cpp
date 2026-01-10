#include <bits/stdc++.h>
using namespace std;

int main() {
    string A;
    cin >> A;

    // 1. First letter uppercase
    A[0] = toupper(A[0]);

    string password = "";

    // 2–4. Character replacements
    for (char c : A) {
        if (c == 's') {
            password += '$';
        }
        else if (c == 'i') {
            password += '!';
        }
        else if (c == 'o') {
            password += "()";
        }
        else {
            password += c;
        }
    }

    // 5. Add dot at the end
    password += '.';

    cout << password << endl;

    return 0;
}
