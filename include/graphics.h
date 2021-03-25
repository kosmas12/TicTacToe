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

#ifdef MAIN_INCLUDE
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN int windowWidth;
EXTERN int windowHeight;
EXTERN TTF_Font *smallFont;
EXTERN TTF_Font *bigFont;
EXTERN TTF_Font *ultraSmallFont;
EXTERN SDL_Surface *bgSurface;
EXTERN SDL_Window *window;
EXTERN SDL_Surface *windowSurface;
EXTERN Uint32 Rmask;
EXTERN Uint32 Gmask;
EXTERN Uint32 Bmask;
EXTERN Uint32 Amask;


void screenInit();
int windowInit();
void ResetScreen();
void InitStdText();
void UpdateScore();
void DrawField();

#endif //TICTACTOE_GRAPHICS_H
