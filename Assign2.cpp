
#include <graphics.h>
#include <iostream>


using namespace std;

void drawRectangle() {
    rectangle(100, 100, 300, 200);
}


void floodFill(int x, int y, int oldColor, int newColor) {
 
    if (getpixel(x, y) == oldColor) {
       
        putpixel(x, y, newColor);
        delay(1);

        // Recursively fill surrounding pixels (8-connected)
        floodFill(x + 1, y, oldColor, newColor);   // Right
        floodFill(x - 1, y, oldColor, newColor);   // Left
        floodFill(x, y + 1, oldColor, newColor);   // Down
        floodFill(x, y - 1, oldColor, newColor);   // Up
        floodFill(x + 1, y + 1, oldColor, newColor); // Down-Right
        floodFill(x - 1, y - 1, oldColor, newColor); // Up-Left
        floodFill(x + 1, y - 1, oldColor, newColor); // Up-Right
        floodFill(x - 1, y + 1, oldColor, newColor); // Down-Left
    }
}

// Boundary fill algorithm
void boundaryFill(int x, int y, int boundaryColor, int nColor) {
   
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != nColor) {
       
        putpixel(x, y, nColor);
        delay(1);

        // Recursively fill surrounding pixels (8-connected)
        boundaryFill(x + 1, y, boundaryColor, nColor);   // Right
        boundaryFill(x - 1, y, boundaryColor, nColor);   // Left
        boundaryFill(x, y + 1, boundaryColor, nColor);   // Down
        boundaryFill(x, y - 1, boundaryColor, nColor);   // Up
        boundaryFill(x + 1, y + 1, boundaryColor, nColor); // Down-Right
        boundaryFill(x - 1, y - 1, boundaryColor, nColor); // Up-Left
        boundaryFill(x + 1, y - 1, boundaryColor, nColor); // Up-Right
        boundaryFill(x - 1, y + 1, boundaryColor, nColor); // Down-Left
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
   
   

    // Perform boundary fill
    setcolor(WHITE);
    drawRectangle();
    int nColor = 14;
    boundaryFill(150, 150, WHITE, nColor);
    drawRectangle();

    int oldColor = nColor;
    int newColor = 11;

    // Perform flood fill
    floodFill(101, 101, oldColor, newColor);

    delay(5000);
    closegraph();
    return 0;
}