#include "../include/game_logic.h"
#include <assert.h>
#include <stdio.h>


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
	'x', ' ', 'x',
	'o', ' ', 'x'
};

// no winner
char gamemap05[9] = {
	'x', ' ', 'o',
	'o', ' ', 'o',
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

// o - winner
char gamemap14[9] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	'o', ' ', 'o'
};

// o - winner
char gamemap15[9] = {
	'x', ' ', 'x',
	'o', ' ', 'o',
	'o', 'o', 'o'
};

// o - winner
char gamemap16[9] = {
	'o', ' ', 'o',
	'o', 'o', 'o',
	'o', 'o', 'o'
};

// o - winner
char gamemap17[9] = {
	'o', 'x', 'o',
	'o', ' ', 'o',
	'o', 'x', 'o'
};

// o - winner
char gamemap18[9] = {
	'o', 'o', 'x',
	'o', 'o', 'x',
	'o', 'o', ' '
};

// o - winner
char gamemap19[9] = {
	'o', ' ', 'o',
	'o', 'o', 'o',
	'x', ' ', 'x'
};


int main(){
	// Empty gamemap
	assert(' ' == findWinner(gamemap));
	assert(-1 == findNextWinner(gamemap, 'o'));

	// no winner
	assert(' ' == findWinner(gamemap01));
	assert(-1 == findNextWinner(gamemap01, 'o'));

	// no winner
	assert(' ' == findWinner(gamemap02));
	assert(-1 == findNextWinner(gamemap02, 'o'));

	// o - winner
	assert('o' == findWinner(gamemap03));
	assert(-1 == findNextWinner(gamemap03, 'o'));

	// no winner
	assert(' ' == findWinner(gamemap04));
	assert(4 == findNextWinner(gamemap04, 'o'));

	// no winner
	assert(' ' == findWinner(gamemap05));
	assert(4 == findNextWinner(gamemap05, 'o'));

	// x - winner
	assert('x' == findWinner(gamemap06));
	assert(-1 == findNextWinner(gamemap06, 'o'));

	// o - winner
	assert('o' == findWinner(gamemap07));
	assert('o' == findWinner(gamemap08));
	assert('o' == findWinner(gamemap09));
	assert('o' == findWinner(gamemap10));
	assert('o' == findWinner(gamemap11));
	assert('o' == findWinner(gamemap12));
	assert('o' == findWinner(gamemap13));
	assert(-1 == findNextWinner(gamemap07, 'o'));
	assert(-1 == findNextWinner(gamemap08, 'o'));
	assert(-1 == findNextWinner(gamemap09, 'o'));
	assert(-1 == findNextWinner(gamemap11, 'o'));
	assert(-1 == findNextWinner(gamemap12, 'o'));
	assert(-1 == findNextWinner(gamemap13, 'o'));

	assert(7 == findNextWinner(gamemap14, 'x'));
	assert(1 == findNextWinner(gamemap15, 'o'));
	assert(-1 == findNextWinner(gamemap16, 'o'));
	assert(4 == findNextWinner(gamemap17, 'o'));
	assert(8 == findNextWinner(gamemap18, 'o'));
	assert(7 == findNextWinner(gamemap19, 'o'));
	assert(1 == findNextWinner(gamemap19, 'x'));


	return 0;
}
