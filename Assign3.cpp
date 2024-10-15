#include <iostream>
#include <graphics.h> 
#include <cstdlib>

using namespace std;


const int xmin = 100, ymin = 100, xmax = 500, ymax = 400;

enum RegionCode {
    INSIDE = 0,
    LEFT = 1,
    RIGHT = 2,
    BOTTOM = 4,
    TOP = 8
};


int computeRegionCode(int x, int y) {
    int code = INSIDE;

    if (x < xmin)       
        code |= LEFT;
    else if (x > xmax)  
        code |= RIGHT;
    if (y < ymin)      
        code |= BOTTOM;
    else if (y > ymax)  
        code |= TOP;

    return code;
}


void cohenSutherlandClip(int x0, int y0, int x1, int y1) {
    int code0 = computeRegionCode(x0, y0);
    int code1 = computeRegionCode(x1, y1);
    bool accept = false;

    while (true) {
        if ((code0 | code1) == 0) {
     
            accept = true;
            break;
        } else if ((code0 & code1) != 0) {
           
            break;
        } else {
            int codeOut;
            int x, y;

         
            if (code0 != 0) {
                codeOut = code0;
            } else {
                codeOut = code1;
            }

    
            if (codeOut & TOP) {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (codeOut & BOTTOM) {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (codeOut & RIGHT) {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else if (codeOut & LEFT) {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            
            if (codeOut == code0) {
                x0 = x;
                y0 = y;
                code0 = computeRegionCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            }
        }
    }

    if (accept) {
 
        line(x0, y0, x1, y1);
        cout << "Line accepted from (" << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ")" << endl;
    } else {
        cout << "Line rejected" << endl;
    }
}

int main() {

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    rectangle(xmin, ymin, xmax, ymax);
    
 
    int x0 = 150, y0 = 250; 
    int x1 = 400, y1 = 50;  
   
    cohenSutherlandClip(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
