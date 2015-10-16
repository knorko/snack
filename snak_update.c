#include <stdio.h>
#include <stdlib.h>
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
                case POINT:
                    printf("X%s", BLANK);break;
            }
        }
        printf("\n");
    }
}
