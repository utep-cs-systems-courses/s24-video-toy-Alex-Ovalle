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
    drawFilledCircle(screenWidth/2, screenHeight/2, 50, faceColor);  // Draw a filled circle for the face

    // Draw eyes
    drawFilledCircle((screenWidth/2)-20, (screenHeight/2)-15, 10, otherColor);    // Left eye
    drawFilledCircle((screenWidth/2)+20, (screenHeight/2)-15, 10, otherColor);    // Right eye

    // Draw whiskers
    fillRectangle(screenWidth / 2 - 30, screenHeight / 2, 15, 2, otherColor); // Left whisker
    fillRectangle(screenWidth / 2 + 15, screenHeight / 2, 15, 2, otherColor); // Right whisker


    // Draw mouth
    fillRectangle(screenWidth / 2 - 20, screenHeight / 2 + 30, 40, 2, otherColor);
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
