#include <graphics.h>
#include <cmath>
#include <iostream>
#include <algorithm> // For std::min and std::max

void translation() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(50, 50, 150, 120);
    delay(2000);

    int constant = 200;
    rectangle(50 + constant, 50 + constant, 150 + constant, 120 + constant);

    delay(3000);
    closegraph();
}

void scaling() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    rectangle(50, 50, 150, 120);
    delay(500);

    int constant = 2;
    rectangle(50 * constant, 50 * constant, 150 * constant, 120 * constant);
    delay(3000);
    closegraph();
}

void rotation() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int left = 50, top = 50, right = 150, bottom = 120;

    rectangle(left, top, right, bottom);
    delay(1000);

    float angle = 45; // Example rotation angle
    float rad = angle * (M_PI / 180); // Convert degrees to radians
    
    float centerX = (left + right) / 2.0;
    float centerY = (top + bottom) / 2.0;

    auto rotatePoint = [&](float x, float y) {
        float newX = centerX + (x - centerX) * cos(rad) - (y - centerY) * sin(rad);
        float newY = centerY + (x - centerX) * sin(rad) + (y - centerY) * cos(rad);
        return std::make_pair(newX, newY);
    };

    auto p1 = rotatePoint(left, top);
    auto p2 = rotatePoint(right, top);
    auto p3 = rotatePoint(right, bottom);
    auto p4 = rotatePoint(left, bottom);

    line(p1.first, p1.second, p2.first, p2.second);
    line(p2.first, p2.second, p3.first, p3.second);
    line(p3.first, p3.second, p4.first, p4.second);
    line(p4.first, p4.second, p1.first, p1.second);

    delay(3000);
    closegraph();
}

using namespace std;

int main() {
    while (1) {
        cout << "Choose the choice: 1) Translation 2) Scaling 3) Rotation 4) Exit " << endl;
        int ch;
        cin >> ch;

        switch (ch) {
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        case 4:
            goto hi;
            break;
        default:
            cout << "Please provide correct input" << endl;
            break;
        }
    }

hi:
    return 0;
}
