/*
This file is part of TicTacToe.

TicTacToe is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TicTacToe is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TicTacToe.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "graphics.h"
#include "common.h"
#if !defined(NXDK)
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#define RESOURCEDIR "../resources/"
#else
#include <hal/video.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#define RESOURCEDIR "D:\\resources\\"
#endif

#define PLAYER_SCORE_TEXT "You: %d"
#define AI_SCORE_TEXT "AI: %d"
#define DRAWS_TEXT "Draws: %d"
#define OUTPUT_BUFFER_SIZE 32


// Set width and height, if on Xbox initialize video
void screenInit() {

    windowWidth = 640;
    windowHeight = 480;

#if defined(NXDK)
    XVideoSetMode(windowWidth, windowHeight, 32, REFRESH_DEFAULT);
#endif

}

// Create a window
int windowInit() {
    window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Couldn't create window! Reason: %s\n", SDL_GetError());
        return 1;
    }

    windowSurface = SDL_GetWindowSurface(window);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    Rmask = 0xFF000000;
    Gmask = 0x00FF0000;
    Bmask = 0x0000FF00;
    Amask = 0x000000FF;
#else
    Rmask = 0x000000FF;
    Gmask = 0x0000FF00;
    Bmask = 0x00FF0000;
    Amask = 0xFF000000;
#endif

    bgSurface = SDL_CreateRGBSurface(0, windowWidth, windowHeight, 32, Rmask, Gmask, Bmask, Amask);

    loadImages();
    DrawField();

    return 0;
}

void ResetScreen() {
    SDL_BlitSurface(bgSurface, NULL, windowSurface, NULL);
    SDL_UpdateWindowSurface(window);
}

int loadImages() {
    xSurface = IMG_Load(RESOURCEDIR"X.png");
    if (!xSurface) {
        printf("Couldn't load the X image! Reason: %s\n", SDL_GetError());
        return 1;
    }

    oSurface = IMG_Load(RESOURCEDIR"O.png");
    if (!oSurface) {
        printf("Couldn't load the O image! Reason: %s\n", SDL_GetError());
        return 1;
    }
    cursorSurface = IMG_Load(RESOURCEDIR"cursor.png");
    if (!cursorSurface) {
        printf("Couldn't load the cursor image! Reason: %s\n", SDL_GetError());
        return 1;
    }

    // Optimize the loaded images by using the window format
    xSurface = SDL_ConvertSurface(xSurface, windowSurface->format, 0);
    oSurface = SDL_ConvertSurface(oSurface, windowSurface->format, 0);
    cursorSurface = SDL_ConvertSurface(cursorSurface, windowSurface->format, 0);

}

void InitStdText() {
    smallFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 30);
    if (!smallFont) {
        printf("Couldn't load small font! Reason: %s\n", SDL_GetError());
        return;
    }

    bigFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 58);
    if (!bigFont) {
        printf("Couldn't load big font! Reason: %s\n", SDL_GetError());
        return;
    }

    ultraSmallFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 25);
    if (!bigFont) {
        printf("Couldn't load ultra small font! Reason: %s\n", SDL_GetError());
        return;
    }

    SDL_Color textColor = {255, 255, 255, 255};

    SDL_Rect namePos = {windowWidth-170, 40, 60, 70};
    SDL_Surface *name = TTF_RenderText_Blended(smallFont, "TicTacToe", textColor);
    SDL_BlitSurface(name, NULL, bgSurface, &namePos);
    SDL_FreeSurface(name);

    SDL_Rect madeByPos = {windowWidth-170, 130, 70, 80};
    SDL_Surface *madeBy = TTF_RenderText_Blended_Wrapped(ultraSmallFont, "Made by Teufelchen1 and kosmas12", textColor, 170);
    SDL_BlitSurface(madeBy, NULL, bgSurface, &madeByPos);
    SDL_FreeSurface(madeBy);

    SDL_Rect copyrightPos = {20, 420, 100, 60};
    SDL_Surface *copyright = TTF_RenderText_Blended(smallFont, "Copyright 2021 and licensed under the GPL3", textColor);
    SDL_BlitSurface(copyright, NULL, bgSurface, &copyrightPos);
    SDL_FreeSurface(copyright);

    SDL_Rect controls1Pos = {windowWidth-170, 310, 100, 60};
    SDL_Surface *controls1 = TTF_RenderText_Blended_Wrapped(ultraSmallFont, "D-Pad or arrow keys to move", textColor, 120);
    SDL_BlitSurface(controls1, NULL, bgSurface, &controls1Pos);
    SDL_FreeSurface(controls1);

    SDL_Rect controls2Pos = {5, 320, 100, 60};
    SDL_Surface *controls2 = TTF_RenderText_Blended_Wrapped(ultraSmallFont, "A or Enter to Confirm selection", textColor, 120);
    SDL_BlitSurface(controls2, NULL, bgSurface, &controls2Pos);
    SDL_FreeSurface(controls2);

}

// Calculates a number that can be used for x or y, used to calculate letter positions
// Takes a field line width and a character width, in any order
int calculatePos(int num, int width1, int width2) {
    // If the number is out of bounds, return maximum/minimum possible
    if (num > 2) {
        return (2*width1)+(2*width2);
    }
    if (num < 0) {
        return (0*width1)+(0*width2);
    }

    return (num*width1)+(num*width2);
}

void DrawLetter(int x, int y, char letter) {
    int width = 32;
    int height = 25;
    int lineThickness = 5;
    int letterWidth = 85;

    SDL_Rect pos = {
            calculatePos(x, lineThickness, letterWidth),
            calculatePos(y, lineThickness, letterWidth),
            windowWidth/width,
            windowHeight/height
    };

    // Erase selection cursor
    SDL_FillRect(windowSurface, &pos, SDL_MapRGB(windowSurface->format, 0, 0, 0));

    // Draw letter
    if(letter == 'O') {
        SDL_BlitSurface(oSurface, NULL, windowSurface, &pos);
    }
    else {
        SDL_BlitSurface(xSurface, NULL, windowSurface, &pos);
    }

}

void UpdateScore() {
    // Make text white
    SDL_Color textColor = {255, 255, 255, 255};

    char *outputBuffer = (char *) calloc(OUTPUT_BUFFER_SIZE, sizeof(char));

    SDL_Rect pScorePos = {10, 0, OUTPUT_BUFFER_SIZE, 62};
    snprintf(outputBuffer, OUTPUT_BUFFER_SIZE, PLAYER_SCORE_TEXT, playerScore);
    SDL_Surface *pScore = TTF_RenderText_Blended(ultraSmallFont, outputBuffer, textColor);
    SDL_BlitSurface(pScore, NULL, windowSurface, &pScorePos);
    SDL_FreeSurface(pScore);

    SDL_Rect aiScorePos = {10, 40, OUTPUT_BUFFER_SIZE, 20};
    snprintf(outputBuffer, OUTPUT_BUFFER_SIZE, AI_SCORE_TEXT, aiScore);
    SDL_Surface *aScore = TTF_RenderText_Blended(ultraSmallFont, outputBuffer, textColor);
    SDL_BlitSurface(aScore, NULL, windowSurface, &aiScorePos);
    SDL_FreeSurface(aScore);

    SDL_Rect drawsPos = {10, 80, OUTPUT_BUFFER_SIZE, 20};
    snprintf(outputBuffer, OUTPUT_BUFFER_SIZE, DRAWS_TEXT, draws);
    SDL_Surface *drawsSurface = TTF_RenderText_Blended(ultraSmallFont, outputBuffer, textColor);
    SDL_BlitSurface(drawsSurface, NULL, windowSurface, &drawsPos);
    free(outputBuffer);
    SDL_FreeSurface(drawsSurface);

    SDL_UpdateWindowSurface(window);
}

void DrawField() {

    SDL_FillRect(bgSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));

    int verty = 40;
    int horx = 110;
    int hor1y = 130;
    int hor2y = 300;

    int linethickness = 5;
    int verth = 370;
    int horw = 340;

    SDL_Rect vert1 = {windowWidth/2-130, verty, linethickness, verth};
    SDL_Rect vert2 = {windowWidth/2+40, verty, linethickness, verth};
    SDL_Rect hor1 = {horx, hor1y, horw, linethickness};
    SDL_Rect hor2 = {horx, hor2y, horw, linethickness};

    SDL_FillRect(bgSurface, &vert1, SDL_MapRGB(bgSurface->format, 255, 255, 255));
    SDL_FillRect(bgSurface, &vert2, SDL_MapRGB(bgSurface->format, 255, 255, 255));
    SDL_FillRect(bgSurface, &hor1, SDL_MapRGB(bgSurface->format, 255, 255, 255));
    SDL_FillRect(bgSurface, &hor2, SDL_MapRGB(bgSurface->format, 255, 255, 255));

    InitStdText();
    ResetScreen();
}

