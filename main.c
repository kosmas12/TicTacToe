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
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#else
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <hal/video.h>
#include <hal/debug.h>
#define printf(...) debugPrint(__VA_ARGS__)
#endif
#include "include/graphics.h"
#include "include/common.h"
#include "include/input.h"

SDL_Event event;

int Init() {
    screenInit();

    printf("Welcome to Tic Tac Toe! Copyright (C) 2021\n");

    // On success these return 0
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Couldn't initialize SDL! Reason: %s\n", SDL_GetError());
    }

    if(TTF_Init() != 0) {
        printf("Couldn't initialize SDL_ttf! Reason: %s\n", SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        printf("Couldn't initialize SDL_image! Reason: %s\n", SDL_GetError());
    }

    playerScore = 0;
    aiScore = 0;
    draws = 0;

    int ret = windowInit();

    initButtonMap(buttons);

    return ret;
}

void Quit(int exitcode) {
    TTF_CloseFont(ultraSmallFont);
    TTF_CloseFont(smallFont);
    TTF_CloseFont(bigFont);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    exit(exitcode);
}

int main() {

    int exitted = 0;

    if(Init() == 1) {
        Quit(1);
    }

    DrawField();
    UpdateScore();
    enum gameLogicButton currentlyPressedButton;

    while (!exitted) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    exitted = 1;
                    break;
                case SDL_KEYDOWN:
                    currentlyPressedButton = getCurrentlyPressedLogicButton(event, buttons, 5);
                    break;
                default:
                    break;
            }
        }
    }

    Quit(0);

    return 0;
}
