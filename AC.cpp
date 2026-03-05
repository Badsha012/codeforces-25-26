#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int hours = 0;
    int burned = 0;

    while (a > 0) {
        hours += a;          // candles burn
        burned += a;         // collect burned candles
        a = burned / b;      // make new candles
        burned = burned % b; // remaining burned candles
    }

    cout << hours << endl;

    return 0;
}