#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string s;
    // Read the entire line of input
    getline(cin, s);

    set<char> distinct_letters;
    // Iterate through the string
    for (char c : s) {
    
        if (c >= 'a' && c <= 'z') {
            distinct_letters.insert(c);
        }
    }

    // The size of the set is the count of distinct letters
    cout << distinct_letters.size() << endl;

    return 0;
}
