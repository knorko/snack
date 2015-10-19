#include "snak.h"
#include <stdio.h>

int main(){
    state playfield[PF_SIZE][PF_SIZE];
    Snake willi;
    Point snacks[MAX_LEN];
	Point *snac_ptr = snacks;

    initSnake(&willi);
    initSnacks(snac_ptr);

	char input = 'x';
	while(input != 'q'){
	    initPlayfield(playfield);
		updateSnake(&willi, INIT);
		updatePlayfield(willi, snacks, playfield);
	    drawPlayfield(playfield);
		input = getchar();
	}
}
