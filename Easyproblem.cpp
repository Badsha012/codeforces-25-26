#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int countVowels = 0;

    for (char c : s) {
        c = tolower(c);  // convert to lowercase
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            countVowels++;
        }
    }

    cout << countVowels << endl;
    return 0;
}
