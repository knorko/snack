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
    for(int i = 0; i < MAX_LEN; i++){
        snacks[i].x = rand() % PF_SIZE;
        snacks[i].y = rand() % PF_SIZE;
		snacks[i].dir = INIT;
    }
}

void updatePlayfield(Snake snake, Point snacks[MAX_LEN], state pf[PF_SIZE][PF_SIZE]){
    if(	snake.body[0].x >= PF_SIZE || 
		snake.body[0].y >= PF_SIZE || 
		snake.body[0].x < 0 || 
		snake.body[0].y < 0){printf("GAME OVER\n"); return;}
	int i;
    //Insert Snake Data into Playfield
    for(i = 0; i <= snake.size; i++){
        pf[snake.body[i].x][snake.body[i].y] = SNAKE;
        //DEBUG: outcomment for release
         
    }
    i = 0;
    //Insert Snack data
    pf[snacks[0].x][snacks[0].y] = SNACK;
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
	//Update Body Direction

	for(int i = s->size; i > 0; --i){
	//DEBUG:

	printf("DEBUG:\nSnake[%d]: X:%d Y:%d DIR:%d\n", i,s->body[i].x, s->body[i].y, 
			s->body[i].dir);

		s->body[i].x = s->body[i-1].x;
		s->body[i].y = s->body[i-1].y; 
	}
}
