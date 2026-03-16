#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long a, sum1 = 0, sum2 = 0, sum3 = 0;

    // first list
    for(int i = 0; i < n; i++){
        cin >> a;
        sum1 += a;
    }

    // second list
    for(int i = 0; i < n-1; i++){
        cin >> a;
        sum2 += a;
    }

    // third list
    for(int i = 0; i < n-2; i++){
        cin >> a;
        sum3 += a;
    }

    cout << sum1 - sum2 << endl;
    cout << sum2 - sum3 << endl;

    return 0;
}