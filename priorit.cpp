#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N > 1 && N % 2 == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
