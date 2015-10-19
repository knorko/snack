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
		printf("Main: Willi headed: %d\n", willi.body[0].dir);
		if(input == 'a' && (willi.body[0].dir == WEST || willi.body[0].dir == EAST)) 		
			updateSnake(&willi, NORTH); 
		else if(input == 'a' && (willi.body[0].dir == NORTH || 
			willi.body[0].dir == SOUTH)) 
			updateSnake(&willi,WEST);
		else if(input == 'x' && (willi.body[0].dir == EAST || 
			willi.body[0].dir == WEST))	
			updateSnake(&willi, SOUTH);
		else if(input == 'x' && (willi.body[0].dir == SOUTH || 
			willi.body[0].dir == NORTH)) 
			updateSnake(&willi, EAST);
		else {updateSnake(&willi, willi.body[0].dir); printf("INPUT = NULL\n");}
		updatePlayfield(willi, snacks, playfield);
	    drawPlayfield(playfield);
		input = getchar();
		count --;
	}
}
