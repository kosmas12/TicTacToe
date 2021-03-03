//
// Created by kosmas on 11/2/21.
//

#ifndef TICTACTOE_COMMON_H
#define TICTACTOE_COMMON_H

#ifdef MAIN_INCLUDE
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN int playerScore;
EXTERN int aiScore;
EXTERN int draws;

#endif //TICTACTOE_COMMON_H
