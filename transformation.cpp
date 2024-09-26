#include <graphics.h> 
#include <cmath>
#include <iostream>

void translation()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(50, 50, 150, 120);
    delay(2000);
    cleardevice();

    int constant = 200;
    rectangle(50 + constant, 50 + constant, 150 + constant, 120 + constant);

    delay(5000);
    closegraph();
}

void scaling()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(50, 50, 150, 120);
    delay(500);
    cleardevice();

    int constant = 2;
    rectangle(50 * constant, 50 * constant, 150 * constant, 120 * constant);

    delay(5000);
    closegraph();
}

void rotation()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 50, y1 = 50, x2 = 150, y2 = 120;
    int x_center = (x1 + x2) / 2, y_center = (y1 + y2) / 2;
    double angle = 45; // rotate by 45 degrees

    // convert degree to radian for calculation
    double radian = angle * M_PI / 180;

    int new_x1 = x_center + (x1 - x_center) * cos(radian) - (y1 - y_center) * sin(radian);
    int new_y1 = y_center + (x1 - x_center) * sin(radian) + (y1 - y_center) * cos(radian);
    int new_x2 = x_center + (x2 - x_center) * cos(radian) - (y2 - y_center) * sin(radian);
    int new_y2 = y_center + (x2 - x_center) * sin(radian) + (y2 - y_center) * cos(radian);

    rectangle(new_x1, new_y1, new_x2, new_y2);
    delay(5000);
    closegraph();
}

void reflection()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(50, 50, 150, 120);
    delay(1000);
    cleardevice();

    // Reflect across the x-axis
    int y_reflect = getmaxy() - 50;
    rectangle(50, y_reflect - 120, 150, y_reflect);

    delay(5000);
    closegraph();
}

using namespace std;

int main()
{
    while (1)
    {
        cout << "Choose the choice: 1) Translation 2) Scaling 3) Rotation 4) Reflection 5) Exit" << endl;
        int ch;
        cin >> ch;

        switch (ch)
        {
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
            reflection();
            break;
        case 5:
            goto exit_loop;
            break;
        default:
            cout << "Please provide correct input" << endl;
            break;
        }
    }

exit_loop:
    return 0;
}
