#include "../include/game_logic.h"
#include <assert.h>


char gamemap[9] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	' ', ' ', ' '

};

// no winner
char gamemap01[9] = {
	'x', ' ', 'o',
	'o', ' ', 'x',
	'x', ' ', 'o'
};

// no winner
char gamemap02[9] = {
	'x', 'x', 'o',
	'o', 'o', 'x',
	'x', 'o', 'o'
};

// o - winner
char gamemap03[9] = {
	'x', 'o', 'o',
	'o', 'o', 'x',
	'x', 'o', 'x'
};

// no winner
char gamemap04[9] = {
	'x', ' ', 'o',
	'x', ' ', 'o',
	'o', ' ', 'x'
};

// no winner
char gamemap05[9] = {
	'x', ' ', 'o',
	' ', ' ', ' ',
	'o', ' ', 'x'
};

// x - winner
char gamemap06[9] = {
	'x', ' ', 'o',
	' ', 'x', ' ',
	'o', ' ', 'x'
};

// o - winner
char gamemap07[9] = {
	'x', ' ', 'o',
	' ', 'o', ' ',
	'o', ' ', 'x'
};

// o - winner
char gamemap08[9] = {
	'o', ' ', ' ',
	'o', ' ', ' ',
	'o', ' ', ' '
};

// o - winner
char gamemap09[9] = {
	' ', 'o', ' ',
	' ', 'o', ' ',
	' ', 'o', ' '
};

// o - winner
char gamemap10[9] = {
	' ', ' ', 'o',
	' ', ' ', 'o',
	' ', ' ', 'o'
};

// o - winner
char gamemap11[9] = {
	'o', 'o', 'o',
	' ', ' ', ' ',
	' ', ' ', ' '
};

// o - winner
char gamemap12[9] = {
	' ', ' ', ' ',
	'o', 'o', 'o',
	' ', ' ', ' '
};

// o - winner
char gamemap13[9] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	'o', 'o', 'o'
};


int main(){
	// Empty gamemap
	assert(' ' == findWinner(gamemap));

	// no winner
	assert(' ' == findWinner(gamemap01));

	// no winner
	assert(' ' == findWinner(gamemap02));

	// o - winner
	assert('o' == findWinner(gamemap03));

	// no winner
	assert(' ' == findWinner(gamemap04));

	// no winner
	assert(' ' == findWinner(gamemap05));

	// x - winner
	assert('x' == findWinner(gamemap06));

	// o - winner
	assert('o' == findWinner(gamemap07));
	assert('o' == findWinner(gamemap08));
	assert('o' == findWinner(gamemap09));
	assert('o' == findWinner(gamemap10));
	assert('o' == findWinner(gamemap11));
	assert('o' == findWinner(gamemap12));
	assert('o' == findWinner(gamemap13));

	return 0;
}
