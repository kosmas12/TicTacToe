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

#define MAIN_INCLUDE
#include "graphics.h"
#include "common.h"
#if !defined(NXDK)
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#define RESOURCEDIR "./"
#else
#include <hal/video.h>
#include <SDL.h>
#include <SDL_ttf.h>
#define RESOURCEDIR "D:\\"
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

    bgSurface = SDL_CreateRGBSurface(NULL, windowWidth, windowHeight, 32, Rmask, Gmask, Bmask, Amask);

    DrawField();

    return 0;
}

void ResetScreen() {
    SDL_BlitSurface(bgSurface, NULL, windowSurface, NULL);
    SDL_UpdateWindowSurface(window);
}

void InitStdText() {
    smallFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 30);
    if (!smallFont) {
        printf("Couldn't load small font! Reason: %s\n", SDL_GetError());
        TTF_Quit();
        SDL_Quit();
        return;
    }

    bigFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 58);
    if (!bigFont) {
        printf("Couldn't load big font! Reason: %s\n", SDL_GetError());
        TTF_CloseFont(smallFont);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    ultraSmallFont = TTF_OpenFont(RESOURCEDIR"Serif.ttf", 25);
    if (!bigFont) {
        printf("Couldn't load ultra small font! Reason: %s\n", SDL_GetError());
        TTF_CloseFont(bigFont);
        TTF_CloseFont(smallFont);
        TTF_Quit();
        SDL_Quit();
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

    int verty = 5;
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

