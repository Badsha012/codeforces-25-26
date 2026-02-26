#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
    string rhymeLine;
    getline(cin, rhymeLine);
    stringstream ss(rhymeLine);
    string word;
    int wordCount = 0;
    while (ss >> word) {
        wordCount++;
    }

    int n;
    cin >> n;
    vector<string> kids(n);
    for (int i = 0; i < n; i++) {
        cin >> kids[i];
    }

    vector<string> team1, team2;
    int currentIndex = 0;

  
    for (int round = 1; round <= n; round++) {
        
        currentIndex = (currentIndex + wordCount - 1) % kids.size();

       
        if (round % 2 != 0) {
            team1.push_back(kids[currentIndex]);
        } else {
            team2.push_back(kids[currentIndex]);
        }

        
        kids.erase(kids.begin() + currentIndex);

    }

    
    cout << team1.size() << "\n";
    for (const string& name : team1) {
        cout << name << "\n";
    }

    
    cout << team2.size() << "\n";
    for (const string& name : team2) {
        cout << name << "\n";
    }

    return 0;
}