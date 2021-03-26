#include <stdio.h>
#include "game_logic.h"


char checkForThree(char a, char b, char c){
	if(a == b && a == c)
		return a;
	return ' ';
}


char findWinner(char map[9]){
	char c = ' ';

	// collumn
	for(int i = 0; i < 3; i++){
		c = checkForThree(map[0*3+i], map[1*3+i], map[2*3+i]);
		if (c != ' ')
			return c;
	}

	// row
	for(int i = 0; i < 3; i++){
		c = checkForThree(map[i*3+0], map[i*3+1], map[i*3+2]);
		if (c != ' ')
			return c;
	}

	// diagonal
	c = checkForThree(map[0*3+0], map[1*3+1], map[2*3+2]);
	if (c != ' ')
		return c;
	c = checkForThree(map[0*3+2], map[1*3+1], map[2*3+0]);
	if (c != ' ')
		return c;
	return ' ';
}


int findFreeSlot(char map[9]){
	for(int i = 0; i < 9; i++){
		if(map[i] == ' ')
			return i;
	}
	return -1;
}


int checkForTwo(char a, char b, char c){
	if(a == b && a != c && c == ' ')
		return 2;
	if(a == c && a != b && b == ' ')
		return 1;
	if(b == c && b != a && a == ' ')
		return 0;
	return -1;
}

// Checks if c is empty and if a && b are the enemy
// Thereby showing that if c is taken by the enemy in the next round,
// the enemy wins by having three in a row
int isNextWin(char a, char b, char c, char player){
	return (a == b && a != player && c == ' ' && a != ' ');
}

// finds one empty tile, which can be used by the enemie to win next round
int findNextWinner(char map[9], char player){
	char a;
	char b;
	char c;

	// columns & rows
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < 3; i++) {
			a = map[3*k+((1+i)%3)];
			b = map[3*k+((2+i)%3)];
			c = map[3*k+i];
			if(isNextWin(a, b, c, player))
				return 3*k+i;

			a = map[3*((1+i)%3)+k];
			b = map[3*((2+i)%3)+k];
			c = map[3*i+k];
			if(isNextWin(a, b, c, player))
				return 3*i+k;
		}
	}

	// diagonals
	a = map[0];
	b = map[8];
	c = map[4];
	if(isNextWin(a, b, c, player))
		return 4;

	a = map[2];
	b = map[6];
	c = map[4];
	if(isNextWin(a, b, c, player))
		return 4;

	return -1;
}
