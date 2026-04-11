#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;

    string s = "";
    int currentIndex = 0;
    int gap = 1;

    // Keep jumping through the string based on the increasing gap
    while (currentIndex < n) {
        s += t[currentIndex]; // Pick the character
        currentIndex += gap;  // Move to the next block
        gap++;                // Increase the size of the next block
    }

    cout << s << endl;

    return 0;
}