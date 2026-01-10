#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int mx = 0;  
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
    }

    cout << mx << endl;
    return 0;
}
