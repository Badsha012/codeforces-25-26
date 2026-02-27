#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

int solve() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    int total_dishes = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_dishes += a[i];
    }

    set<int> possible_winners;

   
    for (int start_player = 0; start_player < n; ++start_player) {
        vector<int> temp_a = a;
        int dishes_left = total_dishes;
        int current_player = start_player;
        int last_winner = -1;

        while (dishes_left > 0) {
            if (temp_a[current_player] > 0) {
                temp_a[current_player]--;
                dishes_left--;
                if (dishes_left == 0) {
                    last_winner = current_player + 1; // Store 1-based index
                }
            }
           
            current_player = (current_player + 1) % n;
        }
        possible_winners.insert(last_winner);
    }

    return possible_winners.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}