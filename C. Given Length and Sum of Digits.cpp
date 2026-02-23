#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int m, s;
    cin >> m >> s;

    // Boundary conditions
    if (s == 0) {
        if (m == 1) cout << "0 0" << endl;
        else cout << "-1 -1" << endl;
        return;
    }
    if (s > 9 * m) {
        cout << "-1 -1" << endl;
        return;
    }

    // Calculating Largest Number
    string largest = "";
    int temp_s = s;
    for (int i = 0; i < m; i++) {
        int digit = min(9, temp_s);
        largest += to_string(digit);
        temp_s -= digit;
    }

    // Calculating Smallest Number
    // We fill it greedily from right to left to keep the left side small
    string smallest = "";
    temp_s = s;
    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
            // Last digit (the leftmost one): use all remaining sum
            smallest += to_string(temp_s);
        } else {
            // Leave at least 1 for the leftmost digit if possible
            int digit = max(0, temp_s - 9 * (m - 1 - i));
            
            // Ensure the very first digit (at index m-1) isn't 0 
            // by taking at least 1 from the sum if we are at the end
            if (i == 0 && digit == 0) {
                // This isn't strictly necessary with the 'max' logic 
                // but helps visualize the "at least 1" rule.
            }
            
            // To make it simpler: Smallest is often just the 
            // reverse of a greedy right-to-left fill.
            int can_put = min(temp_s - (i == m - 1 ? 0 : 1), 9);
            // Wait, let's use a cleaner approach for Smallest:
        }
    }
    
    // Refined Smallest Logic:
    string min_num(m, ' ');
    int cur_s = s;
    for (int i = m - 1; i >= 0; i--) {
        if (i > 0) {
            int d = min(cur_s - 1, 9);
            min_num[i] = d + '0';
            cur_s -= d;
        } else {
            min_num[i] = cur_s + '0';
        }
    }

    cout << min_num << " " << largest << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}