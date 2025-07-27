#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point start, end;
};

int main() {
    int N, P;
    cin >> N >> P;

    vector<Point> posts(P);
    map<pair<int, int>, int> post_indices;

    for (int i = 0; i < P; ++i) {
        cin >> posts[i].x >> posts[i].y;
        post_indices[{posts[i].x, posts[i].y}] = i;
    }

    vector<Segment> segments;
    for (int i = 0; i < P; ++i) {
        Segment s;
        s.start = posts[i];
        s.end = posts[(i + 1) % P];
        segments.push_back(s);
    }

    vector<int> touches(P, 0);

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int start_index = post_indices[{x1, y1}];
        int end_index = post_indices[{x2, y2}];

        int distance = abs(end_index - start_index);
        if (distance > P / 2)
            distance = P - distance;

        touches[start_index]++;
        touches[end_index]++;
        for (int j = 1; j <= distance; ++j) {
            int index = (start_index + j) % P;
            touches[index] += 2;
        }
    }

    for (int i = 0; i < P; ++i) {
        cout << touches[i] << endl;
    }

    return 0;
}
