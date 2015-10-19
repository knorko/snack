#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "snak.h"

void initPlayfield(state playfield[PF_SIZE][PF_SIZE]){
    int x, y;
    for(y = 0; y < PF_SIZE; y++){
        for(x = 0; x < PF_SIZE; x++){
            playfield[x][y] = EMPTY;
        }
    }
}

void drawPlayfield(state playfield[PF_SIZE][PF_SIZE]){
    int x, y;
    for(y = 0; y < PF_SIZE; y++){
        for(x = 0; x <  PF_SIZE; x++){
            switch(playfield[x][y]){
                case EMPTY:
                    printf(" %s", BLANK);break;
                case SNAKE:
                    printf("-%s", BLANK);break;
                case SNACK:
                    printf("X%s", BLANK);break;
            }
        }
        printf("\n");
    }
}

void initSnake(Snake *s){
    s->size = 0;
    s->boazen = 0;
    //initHead
    s->body[0].x = 0;
    s->body[0].y = (int)PF_SIZE/2;
    s->body[0].dir = EAST;
    //init body
    int i;
    for(i = 1; i < MAX_LEN; i++){
        s->body[i].x = -1;
        s->body[i].y = -1;
        s->body[i].dir = INIT;
    }
}

void initSnacks(Point snacks[MAX_LEN]){
    srand(time(NULL));
	snacks[0].x = -1;
	snacks[0].y = -1;
    for(int i = 1; i < MAX_LEN; i++){
        snacks[i].x = rand() % PF_SIZE;
        snacks[i].y = rand() % PF_SIZE;
		snacks[i].dir = INIT;
    }
}

void updatePlayfield(Snake *snake, Point snacks[MAX_LEN], state pf[PF_SIZE][PF_SIZE]){
    if(	snake->body[0].x >= PF_SIZE || 
		snake->body[0].y >= PF_SIZE || 
		snake->body[0].x < 0 || 
		snake->body[0].y < 0){printf("GAME OVER\n"); return;}

    //Insert Snack data
	int j = 0;
	Point next_snack;
	while(snacks[j].x == -1){
		next_snack = snacks[j+1];
		j++;
	}
	printf("updatePlayfield: next snack at: P(%d %d)\n", next_snack.x, next_snack.y);
	pf[next_snack.x][next_snack.y] = SNACK;

	//Insert Snake Data
	int i = 0;

    for(i = 0; i <= snake->size; i++){
        pf[snake->body[i].x][snake->body[i].y] = SNAKE; 
    }
	//Check if Snake is on Snack
	if(snake->body[0].x == snacks[j].x && snake->body[0].y == snacks[j].y){
		printf("updatePlayfield: Snake hit Snack\n");
		//grow snake
		snake->size += 1;
		//Add point
		snake->boazen += 1;
		//set current Snacks x coor to minus zero 
		snacks[j].x = -1;
	}

}


void updateSnake(Snake *s, direction dir){
	//Update Head Direction
	s->body[0].dir = dir;

	//Move Head
	switch(s->body[0].dir){
		case NORTH:	s->body[0].y -= 1;break;
		case EAST: 	s->body[0].x += 1;break;
		case SOUTH: s->body[0].y += 1;break;
		case WEST: 	s->body[0].x -= 1;break;
	}
	//DEBUG:
	printf("\nDEBUG:\nSnake size: %d\nSnake Direction: %d\nSnake[0]: P(%d %d)\n",s->size, 
s->body[0].dir, s->body[0].x, s->body[0].y);

	//Move Body
	for(int i = s->size; i > 0; --i){
	//DEBUG:
	printf("Snake[%d]: X:%d Y:%d DIR:%d\n", i,s->body[i].x, s->body[i].y, 
			s->body[i].dir);

		s->body[i].x = s->body[i-1].x;
		s->body[i].y = s->body[i-1].y; 
		s->body[i].dir = s->body[i-1].dir;
	}
}
