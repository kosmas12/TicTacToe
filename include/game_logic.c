#include <assert.h>

char gamemap[3][3] = {
	{ ' ', ' ', ' '},
	{ ' ', ' ', ' '},
	{ ' ', ' ', ' '}
};

// no winner
char gamemap01[3][3] = {
	{ 'x', ' ', 'o'},
	{ 'o', ' ', 'x'},
	{ 'x', ' ', 'o'}
};

// no winner
char gamemap02[3][3] = {
	{ 'x', 'x', 'o'},
	{ 'o', 'o', 'x'},
	{ 'x', 'o', 'o'}
};

// o - winner
char gamemap03[3][3] = {
	{ 'x', 'o', 'o'},
	{ 'o', 'o', 'x'},
	{ 'x', 'o', 'x'}
};

// no winner
char gamemap04[3][3] = {
	{ 'x', ' ', 'o'},
	{ 'x', ' ', 'o'},
	{ 'o', ' ', 'x'}
};

// no winner
char gamemap05[3][3] = {
	{ 'x', ' ', 'o'},
	{ ' ', ' ', ' '},
	{ 'o', ' ', 'x'}
};

// x - winner
char gamemap06[3][3] = {
	{ 'x', ' ', 'o'},
	{ ' ', 'x', ' '},
	{ 'o', ' ', 'x'}
};

// o - winner
char gamemap07[3][3] = {
	{ 'x', ' ', 'o'},
	{ ' ', 'o', ' '},
	{ 'o', ' ', 'x'}
};

// o - winner
char gamemap08[3][3] = {
	{ 'o', ' ', ' '},
	{ 'o', ' ', ' '},
	{ 'o', ' ', ' '}
};

// o - winner
char gamemap09[3][3] = {
	{ ' ', 'o', ' '},
	{ ' ', 'o', ' '},
	{ ' ', 'o', ' '}
};

// o - winner
char gamemap10[3][3] = {
	{ ' ', ' ', 'o'},
	{ ' ', ' ', 'o'},
	{ ' ', ' ', 'o'}
};

// o - winner
char gamemap11[3][3] = {
	{ 'o', 'o', 'o'},
	{ ' ', ' ', ' '},
	{ ' ', ' ', ' '}
};

// o - winner
char gamemap12[3][3] = {
	{ ' ', ' ', ' '},
	{ 'o', 'o', 'o'},
	{ ' ', ' ', ' '}
};

// o - winner
char gamemap13[3][3] = {
	{ ' ', ' ', ' '},
	{ ' ', ' ', ' '},
	{ 'o', 'o', 'o'}
};

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