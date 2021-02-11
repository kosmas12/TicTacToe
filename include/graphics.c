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
#if !defined(NXDK)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

void gfxInit() {

    width = 640;
    height = 480;

#if defined(NXDK)
    XVideoSetMode(width, height, 32, REFRESH_DEFAULT);
#endif

    window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Couldn't create window! Reason: %s", SDL_GetError());
    }

    windowSurface = SDL_GetWindowSurface(window);

}

void DrawField() {
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(window);
}

