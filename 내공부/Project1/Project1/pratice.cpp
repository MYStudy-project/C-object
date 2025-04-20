#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class Rectangle {
public:
    int xmin, xmax, ymin, ymax;
};

int main() {
    ifstream file("input2.txt");
    int N;
    file >> N;

    vector<Rectangle> rects(N);

    int global_xmin = INT32_MAX, global_ymin = INT32_MAX;
    int global_xmax = INT32_MIN, global_ymax = INT32_MIN;

    for (int i = 0; i < N; ++i) {
        file >> rects[i].xmin >> rects[i].xmax >> rects[i].ymin >> rects[i].ymax;
        if (rects[i].xmin < global_xmin) global_xmin = rects[i].xmin;
        if (rects[i].xmax > global_xmax) global_xmax = rects[i].xmax;
        if (rects[i].ymin < global_ymin) global_ymin = rects[i].ymin;
        if (rects[i].ymax > global_ymax) global_ymax = rects[i].ymax;
    }

    file.close();

    double centerX = (global_xmin + global_xmax) / 2.0;
    double centerY = (global_ymin + global_ymax) / 2.0;

    double max_dist = 0;
    vector<pair<int, int>> corners = {
        {global_xmin, global_ymin},
        {global_xmin, global_ymax},
        {global_xmax, global_ymin},
        {global_xmax, global_ymax}
    };

    for (auto p : corners) {
        double dx = centerX - p.first;
        double dy = centerY - p.second;
        double dist = sqrt(dx * dx + dy * dy);
        if (dist > max_dist)
            max_dist = dist;
    }

    cout << "Center: (" << centerX << ", " << centerY << ")" << endl;
    cout << "Radius: " << max_dist << endl;

    return 0;
}
