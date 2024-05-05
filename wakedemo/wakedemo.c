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

    // Draw the left ear 
    for (int y = screenHeight / 2 - 60; y <= screenHeight / 2 - 30; y++) {
      for (int x = screenWidth / 2 - 40; x <= screenWidth / 2 - 20; x++) {
	// Draw only if inside the triangular region
	if (2 * (screenWidth / 2 - x) >= (screenHeight / 2 - y))
	  drawPixel(x, y, otherColor);
      }
    }
    // Draw the right ear
    for (int y = screenHeight / 2 - 60; y <= screenHeight / 2 - 30; y++) {
      for (int x = screenWidth / 2 + 20; x <= screenWidth / 2 + 40; x++) {
	// Draw only if inside the triangular region
	if (2 * (x - screenWidth / 2) >= (screenHeight / 2 - y))
	  drawPixel(x, y, otherColor);
      }
    }
    
    // Draw face
    drawFilledCircle(screenWidth/2, screenHeight/2, 50, faceColor);  // Draw a filled circle for the face

    // Draw the nose
    int noseX = screenWidth / 2;
    int noseY = screenHeight / 2 + 10;
    int noseSize = 8; // Size of the nose
    for (int y = noseY; y < noseY + noseSize; y++) {
      for (int x = noseX - (noseSize - (y - noseY)) / 2; x <= noseX + (noseSize - (y - noseY)) / 2; x++) {
	drawPixel(x, y, otherColor);
      }
    }
    
    // Draw eyes
    drawFilledCircle((screenWidth/2)-20, (screenHeight/2)-15, 10, otherColor);    // Left eye
    drawFilledCircle((screenWidth/2)+20, (screenHeight/2)-15, 10, otherColor);    // Right eye

    // Draw the whiskers (angled lines)
    int x, y;
    // Left whiskers
    for (int i = 0; i < 3; i++) {
      x = screenWidth / 2 - 30;
      y = screenHeight / 2 + 10 + i * 5; // Adjust the angle and length of the whiskers
      while (x > screenWidth / 2 - 50) {
	drawPixel(x, y, BLACK);
	x--;
	y++;
      }
    }
    // Right whiskers
    for (int i = 0; i < 3; i++) {
      x = screenWidth / 2 + 30;
      y = screenHeight / 2 + 10 + i * 5;
      while (x < screenWidth / 2 + 50) {
	drawPixel(x, y, BLACK);
	x++;
	y++;
      }
    }

    
    // Draw mouth
    for (x = screenWidth / 2 - 15; x <= screenWidth / 2 + 15; x++) {
      y = screenHeight / 2 + 35 - (x - screenWidth / 2) * (x - screenWidth / 2) / 30;
      fillRectangle(x, y, 1, 2, otherColor);
    } 
}

void drawFilledCircle(int centerX, int centerY, int radius, unsigned int color) {
    int x,y;
    for (x = centerX - radius; x <= centerX + radius; x++) 
        for (y = centerY - radius; y <= centerY + radius; y++) 
            if ((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY) <= radius * radius) 
                drawPixel(x, y, color);               
}

void drawUnderline(unsigned char col, unsigned char row, unsigned char size)
{
  unsigned char val = 0;
  while(val < size){
      drawPixel(col,row,color);
      col++;
      val++;
    }
}
