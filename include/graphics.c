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
        printf("Couldn't create window! Reason: %s", SDL_GetError());
        return 1;
    }

    windowSurface = SDL_GetWindowSurface(window);
    return 0;
}

void DrawField() {
    SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(window);
}

