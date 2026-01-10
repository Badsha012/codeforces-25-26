#include <bits/stdc++.h>
using namespace std;

int main() {
    double P;
    cin >> P;

    int percent = floor(P);          
    int barValue = (percent / 10);   

    cout << "[";
    for (int i = 0; i < barValue; i++) cout << "+";
    for (int i = barValue; i < 10; i++) cout << ".";
    cout << "] " << percent << "%" << endl;

    return 0;
}
