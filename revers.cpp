#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);   // read full line including spaces

    reverse(s.begin(), s.end());

    cout << s << "\n";
    return 0;
}
