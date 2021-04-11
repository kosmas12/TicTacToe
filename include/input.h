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

#ifndef TICTACTOE_INPUT_H
#define TICTACTOE_INPUT_H

#if !defined(NXDK)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

enum gameLogicButton {
    BUTTON_MOVE_LEFT,
    BUTTON_MOVE_RIGHT,
    BUTTON_MOVE_UP,
    BUTTON_MOVE_DOWN,
    BUTTON_CONFIRM,
    BUTTON_NONE
};

typedef struct {
    SDL_Keycode physicalKBButton;
    SDL_GameControllerButton physicalGCButton;
    enum gameLogicButton logicButton;
}GameButton;

SDL_GameController *controller;
int openedControllers;
GameButton buttons[5];

void initController(SDL_GameController *controller, int *numOpenedControllers);
void initButtonMap(GameButton buttonMap[]);
void closeController(SDL_GameController *controller, int *numOpenedControllers);
enum gameLogicButton getCurrentlyPressedLogicButton(SDL_Event event, GameButton buttonMap[]);

#endif //TICTACTOE_INPUT_H
