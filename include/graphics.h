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
#else
#include <SDL.h>
#endif

int windowWidth;
int windowHeight;

void screenInit();
int windowInit();
void DrawField();

SDL_Window *window;
SDL_Surface *windowSurface;

#endif //TICTACTOE_GRAPHICS_H
