#include <msp430.h>
#include <math.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

unsigned int color = COLOR_GREEN;
unsigned int faceColor = COLOR_BLACK;

void welcome(){
  clearScreen(WHITE);
  drawString5x7(screenWidth/2,screenHeight/2, "Welcome!", COLOR_RED, COLOR_BLACK);
}

// axis zero for col, axis 1 for row
short drawPos[2] = {1,10}, controlPos[2] = {2, 10};
short colVelocity = 1, colLimits[2] = {1, screenWidth/2};

void drawCatFaceEmoji(unsigned int newColor1, unsigned int newColor2) {
    // Clear the screen
    clearScreen(WHITE);

    unsigned int faceColor = newColor1;
    unsigned int otherColor = newColor2;
  
    // Draw face
    drawFilledCircle(64, 32, 30, faceColor);  // Draw a filled circle for the face

    // Draw eyes
    drawFilledCircle(50, 25, 5, otherColor);    // Left eye
    drawFilledCircle(78, 25, 5, otherColor);    // Right eye

    // Draw whiskers
    fillRectangle(50, 35, 40, 30, otherColor);  // Left whisker
    fillRectangle(50, 35, 40, 40, otherColor);
    fillRectangle(78, 35, 88, 30, otherColor);  // Right whisker
    fillRectangle(78, 35, 88, 40, otherColor);

    // Draw mouth (smile)
    fillRectangle(55, 40, 70, 40, otherColor);   // Draw a curved line for the smile
    fillRectangle(55, 41, 70, 41, otherColor);
    fillRectangle(55, 42, 70, 42, otherColor);
    fillRectangle(55, 43, 70, 43, otherColor);
    fillRectangle(55, 44, 70, 44, otherColor);
}

void drawFilledCircle(int centerX, int centerY, int radius, unsigned int color) {
    int x, y;
    for (x = centerX - radius; x <= centerX + radius; x++) 
        for (y = centerY - radius; y <= centerY + radius; y++) 
            if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) 
                drawPixel(x, y, color);               
}

void drawDiagonal(unsigned char col, unsigned char row, unsigned char size)
{
  unsigned char val = 0;

  while(val < size)
    {
      drawPixel(col,row,color);
      col++;
      row--;
      val++;
    }
}
