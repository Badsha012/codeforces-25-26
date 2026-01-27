#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int left = 0;
    int right = n - 1;
    int current_length = n;

    // While there are characters to check and the ends are different
    while (left < right && s[left] != s[right]) {
        left++;
        right--;
        current_length -= 2;
    }

    cout << current_length << endl;
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