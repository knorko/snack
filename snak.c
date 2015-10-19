#include "snak.h"

int main(){
    state playfield[PF_SIZE][PF_SIZE];
    snake willi;
    Point snacks[MAX_LEN];
    initSnake(willi);
    initSnacks(snacks);
    initPlayfield(playfield);
    drawPlayfield(playfield);
}
