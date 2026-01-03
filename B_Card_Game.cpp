#include <iostream>
#include <vector>

using namespace std;


int check_win(int s1, int s2, int sl1, int sl2) {
    int suneet_rounds = 0;
    int slavic_rounds = 0;

    // Round 1
    if (s1 > sl1) suneet_rounds++;
    else if (sl1 > s1) slavic_rounds++;

    // Round 2
    if (s2 > sl2) suneet_rounds++;
    else if (sl2 > s2) slavic_rounds++;

    
    return (suneet_rounds > slavic_rounds) ? 1 : 0;
}

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int total_wins = 0;

    
    total_wins += check_win(a1, a2, b1, b2);
    
   
    total_wins += check_win(a1, a2, b2, b1);

    total_wins += check_win(a2, a1, b1, b2);
    
   
    total_wins += check_win(a2, a1, b2, b1);

    cout << total_wins << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}