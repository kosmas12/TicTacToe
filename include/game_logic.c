#include "game_logic.h"

char checkForThree(char a, char b, char c){
	if(a == b && a == c)
		return a;
	return ' ';
}


char findWinner(char map[3][3]){
	char c = ' ';

	// collumn
	for(int i = 0; i < 3; i++){
		c = checkForThree(map[0][i], map[1][i], map[2][i]);
		if (c != ' ')
			return c;
	}

	// row
	for(int i = 0; i < 3; i++){
		c = checkForThree(map[i][0], map[i][1], map[i][2]);
		if (c != ' ')
			return c;
	}

	// diagonal
	c = checkForThree(map[0][0], map[1][1], map[2][2]);
	if (c != ' ')
		return c;
	c = checkForThree(map[0][2], map[1][1], map[2][0]);
	if (c != ' ')
		return c;
	return ' ';
}
