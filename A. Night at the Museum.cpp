#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int total_rotations = 0;
    char current_char = 'a'; // The pointer starts at 'a'

    for (char target_char : s) {
        // Calculate the absolute distance between characters
        int diff = abs(target_char - current_char);
        
        // The minimum rotations is the lesser of:
        // 1. The direct distance (diff)
        // 2. The wrap-around distance (26 - diff)
        total_rotations += min(diff, 26 - diff);
        
        // Update the current position to the character just printed
        current_char = target_char;
    }

    cout << total_rotations << endl;

    return 0;
}