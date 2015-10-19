#include "snak.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    state playfield[PF_SIZE][PF_SIZE];
    Snake willi;
    Point snacks[MAX_LEN];
	Point *snac_ptr = snacks;

    initSnake(&willi);
    initSnacks(snac_ptr);

	char input = 'p';
	while(input != 'q'){
		system("clear");
	    initPlayfield(playfield);
		if(input == 'a' && (willi.body[0].dir == WEST || willi.body[0].dir == EAST)){ 		
			updateSnake(&willi, NORTH); getchar();}
		else if(input == 'a' && (willi.body[0].dir == NORTH || 
			willi.body[0].dir == SOUTH)) {
			updateSnake(&willi,WEST); getchar();}
		else if(input == 'x' && (willi.body[0].dir == EAST || 
			willi.body[0].dir == WEST)){	
			updateSnake(&willi, SOUTH); getchar();}
		else if(input == 'x' && (willi.body[0].dir == SOUTH || 
			willi.body[0].dir == NORTH)) {
			updateSnake(&willi, EAST); getchar();}
		else updateSnake(&willi, willi.body[0].dir);
		updatePlayfield(&willi, snac_ptr, playfield);
	    drawPlayfield(playfield);
		printf("Play: 'a' -> Up/Left 'x' -> Right/Down 'q' -> quit: ");
		input = getchar();
	}
}
