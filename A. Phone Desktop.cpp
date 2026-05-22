#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    
    // Step 1: Calculate the minimum screens needed just for the 2x2 icons.
    // Each screen can comfortably hold at most two 2x2 icons.
    int screens = (y + 1) / 2;
    
    // Step 2: Calculate how much total space is left on those screens for 1x1 icons.
    int total_cells = screens * 15;
    int used_by_y = y * 4;
    int remaining_cells = total_cells - used_by_y;
    
    // Step 3: If we have more 1x1 icons than remaining cells, add extra screens.
    if (x > remaining_cells) {
        int leftover_x = x - remaining_cells;
        // Each brand new empty screen can hold up to 15 of the 1x1 icons.
        screens += (leftover_x + 14) / 15;
    }
    
    cout << screens << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}