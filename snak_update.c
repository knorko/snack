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
                    printf("O%s", BLANK);break;
                case SNAKE:
                    printf("-%s", BLANK);break;
                case SNACK:
                    printf("X%s", BLANK);break;
            }
        }
        printf("\n");
    }
}
void initSnake(Snake s){    
    s.size = 0;
    s.boazen = 0;
    //initHead
    s.body[0].x = (int)PF_SIZE/2;
    s.body[0].y = (int)PF_SIZE/2;
    s.body[0].dir = EAST;
    //init body
    int i;
    for(i = 1; i < MAX_LEN; i++){
        s.body[i].x = -1;
        s.body[i].y = -1;
        s.body[i].dir = INIT;
    }
    
}
void initSnacks(Point snacks[MAX_LEN]){
    srand(time(NULL));
    Point p;
    p.dir = INIT;
    for(int i = 0; i < MAX_LEN; i++){
        p.x = rand() % PF_SIZE;
        p.y = rand() % PF_SIZE;
        snacks[i] = p;
    }
}
void updatePlayfield(Snake snake, Point snacks[MAX_LEN], state pf[PF_SIZE][PF_SIZE]){
    int i;
    //Insert Snake Data into Playfield
    for(i = 0; i < snake.size; i++){
        pf[snake.body[i].x][snake.body[i].y] = SNAKE;
    }
    i = 0;
    //Insert Snack data
    while(snacks[i].x != -1){
        pf[snacks[i].x][snacks[i].y] = SNACK;
        i++;
    }
}
