#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Distance from point p to segment ab
double pointToSegmentDist(Point p, Point a, Point b) {
    double d2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    if (d2 == 0) return dist(p, a);
    
    // Projection factor t
    double t = ((p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y)) / d2;
    t = max(0.0, min(1.0, t));
    
    Point projection = {a.x + t * (b.x - a.x), a.y + t * (b.y - a.y)};
    return dist(p, projection);
}

void solve() {
    int Ni, No;
    
    cin >> Ni;
    vector<Point> inner(Ni);
    for (int i = 0; i < Ni; ++i) cin >> inner[i].x >> inner[i].y;
    
    cin >> No;
    vector<Point> outer(No);
    for (int i = 0; i < No; ++i) cin >> outer[i].x >> outer[i].y;

    double min_dist = 1e18;

    // Check distance from each inner vertex to each outer edge
    for (int i = 0; i < Ni; ++i) {
        for (int j = 0; j < No; ++j) {
            min_dist = min(min_dist, pointToSegmentDist(inner[i], outer[j], outer[(j + 1) % No]));
        }
    }

    // Check distance from each outer vertex to each inner edge
    for (int i = 0; i < No; ++i) {
        for (int j = 0; j < Ni; ++j) {
            min_dist = min(min_dist, pointToSegmentDist(outer[i], inner[j], inner[(j + 1) % Ni]));
        }
    }

    cout << fixed << setprecision(6) << min_dist << endl;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}