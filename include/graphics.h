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

#ifndef TICTACTOE_GRAPHICS_H
#define TICTACTOE_GRAPHICS_H

#if !defined(NXDK)
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#endif

int windowWidth;
int windowHeight;
TTF_Font *smallFont;
TTF_Font *bigFont;
TTF_Font *ultraSmallFont;
SDL_Surface *bgSurface;
SDL_Window *window;
SDL_Surface *windowSurface;
SDL_Surface *xSurface;
SDL_Surface *oSurface;
SDL_Surface *cursorSurface;
Uint32 Rmask;
Uint32 Gmask;
Uint32 Bmask;
Uint32 Amask;


void screenInit();
int windowInit();
void ResetScreen();
int loadImages();
void InitStdText();
int calculatePos(int num, int width1, int width2);
void DrawLetter(int x, int y, char letter);
void UpdateScore();
void DrawField();

#endif //TICTACTOE_GRAPHICS_H
