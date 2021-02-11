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
#include <hal/video.h>
#include <hal/debug.h>
#define printf(...) debugPrint(__VA_ARGS__)
#endif
#include "include/graphics.h"

SDL_Event event;

void Init() {
    printf("Welcome to Tic Tac Toe! Copyright (C) 2021\n");

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Couldn't initialize SDL! Reason: %s", SDL_GetError());
    }
    gfxInit();
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
        while (SDL_PollEvent(&event)) {
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
