#include "snak.h"

int main(){
    state playfield[PF_SIZE][PF_SIZE];
    Snake willi;
    Point snacks[MAX_LEN];

    initPlayfield(playfield);
    initSnake(&willi);
    initSnacks(snacks);

    updatePlayfield(willi, snacks, playfield);
    drawPlayfield(playfield);
}
