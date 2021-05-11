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

#include "input.h"
#if !defined(NXDK)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

int openedControllers = 0;

void initController(SDL_GameController *controller, int *numOpenedControllers) {
    // Indices start at 0, so if we have opened 1 controller this will start in the second index
    for (int i = *numOpenedControllers; i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            controller = SDL_GameControllerOpen(i);
            if (controller) {
                *numOpenedControllers++;
                break;
            }
            else {
                printf("Could not open Game Controller! Reason: %s\n", SDL_GetError());
            }
        }
    }
}

void initButtonMap(GameButton buttonMap[]) {
    buttonMap[0].physicalKBButton = SDLK_LEFT;
    buttonMap[0].physicalGCButton = SDL_CONTROLLER_BUTTON_DPAD_LEFT;
    buttonMap[0].logicButton = BUTTON_MOVE_LEFT;
    buttonMap[1].physicalKBButton = SDLK_RIGHT;
    buttonMap[1].physicalGCButton = SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
    buttonMap[1].logicButton = BUTTON_MOVE_RIGHT;
    buttonMap[2].physicalKBButton = SDLK_UP;
    buttonMap[2].physicalGCButton = SDL_CONTROLLER_BUTTON_DPAD_UP;
    buttonMap[2].logicButton = BUTTON_MOVE_UP;
    buttonMap[3].physicalKBButton = SDLK_DOWN;
    buttonMap[3].physicalGCButton = SDL_CONTROLLER_BUTTON_DPAD_DOWN;
    buttonMap[3].logicButton = BUTTON_MOVE_DOWN;
    buttonMap[4].physicalKBButton = SDLK_SPACE;
    buttonMap[4].physicalGCButton = SDL_CONTROLLER_BUTTON_A;
    buttonMap[4].logicButton = BUTTON_CONFIRM;
}

void closeController(SDL_GameController *controller, int *numOpenedControllers) {
    if (controller) {
        SDL_GameControllerClose(controller);
        printf("Controller successfully closed!");
        *numOpenedControllers--;
    }
    else {
        printf("Error: Trying to close invalid controller!\n");
    }
}

enum gameLogicButton getCurrentlyPressedLogicButton(SDL_Event event, GameButton buttonMap[], int size) {

    for (int i = 0; i < size; i++) {
        if (event.key.keysym.sym == buttonMap[i].physicalKBButton
        || event.cbutton.button == buttonMap[i].physicalGCButton) {
            return buttonMap[i].logicButton;
        }
    }
    return BUTTON_NONE;
}
