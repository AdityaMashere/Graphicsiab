#include <graphics.h>
#include <iostream>

using namespace std;

void drawRectangles() {
    
    rectangle(100, 100, 300, 200); 
    rectangle(310, 100, 510, 200); 
}

void floodFill(int x, int y, int oldColor, int newColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, newColor);
        delay(0.5);

        floodFill(x + 1, y, oldColor, newColor);   
        floodFill(x - 1, y, oldColor, newColor);  
        floodFill(x, y + 1, oldColor, newColor); 
        floodFill(x, y - 1, oldColor, newColor);   
        floodFill(x + 1, y + 1, oldColor, newColor); 
        floodFill(x - 1, y - 1, oldColor, newColor); 
        floodFill(x + 1, y - 1, oldColor, newColor); 
        floodFill(x - 1, y + 1, oldColor, newColor); 
    }
}

void boundaryFill(int x, int y, int boundaryColor, int nColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != nColor) {
        putpixel(x, y, nColor);
        delay(0.5);

        boundaryFill(x + 1, y, boundaryColor, nColor); 
        boundaryFill(x - 1, y, boundaryColor, nColor);   
        boundaryFill(x, y + 1, boundaryColor, nColor);  
        boundaryFill(x, y - 1, boundaryColor, nColor);  
        boundaryFill(x + 1, y + 1, boundaryColor, nColor);
        boundaryFill(x - 1, y - 1, boundaryColor, nColor); 
        boundaryFill(x + 1, y - 1, boundaryColor, nColor); 
        boundaryFill(x - 1, y + 1, boundaryColor, nColor); 
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);


    setcolor(WHITE);
    drawRectangles();

    floodFill(150, 150, BLACK, 11); 
    boundaryFill(400, 150, WHITE, 10);


    delay(5000);
    closegraph();
    return 0;
}
