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

#include <stdio.h>
#if !defined(NXDK)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#define printf(...) debugPrint(__VA_ARGS__)
#endif
#include "include/graphics.h"

int width;
int height;
SDL_Event event;

void Init() {
#if defined(NXDK)
    XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);
#endif
    printf("Welcome to Tic Tac Toe! Copyright (C) 2021\n");

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Couldn't initialize SDL! Reason: %s", SDL_GetError());
    }

    window = SDL_CreateWindow("TicTacToe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Couldn't create window! Reason: %s", SDL_GetError());
    }
    windowSurface = SDL_GetWindowSurface(window);
}

void Quit() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {

    int exitted = 0;

    Init();

    DrawField();

    while (!exitted) {
        // We only update in case any events happen, so use WaitEvent for lower CPU usage
        while (SDL_WaitEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exitted = 1;
                    break;
            }
        }
    }

    Quit();

    return 0;
}
