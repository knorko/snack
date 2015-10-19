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
	int count = 3;
	while(input != 'q'){
		if(count == 0){
			willi.size += 1;
			count = 3;
		}
	    initPlayfield(playfield);
		updateSnake(&willi, EAST);
		updatePlayfield(willi, snacks, playfield);
	    drawPlayfield(playfield);
		input = getchar();
		count --;
	}
}
