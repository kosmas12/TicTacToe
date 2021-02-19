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

openedControllers = 0;

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
