#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PF_SIZE 16
#define EMPTY 0
#define SNAKE 1
#define POINT 2
#define BLANK "   "

int spwanTimer = 0;

int playfield[PF_SIZE][PF_SIZE];

struct point{
    int x,y;
    int dir;
};
struct snake{
    int x,y;
    int dir;

    struct point head;
    struct point body[PF_SIZE*PF_SIZE];
    int boazen;
};

struct snake willi;

void resetPlayfield() {
    int x, y;

    for(x=0;x<PF_SIZE;x++) {
        for(y=0;y<PF_SIZE;y++) {
            playfield[y][x] = EMPTY;
        }
    }
}

void updatePlayfield(){
    int x,y;
    for(x = 0; x < PF_SIZE; x++){
        for(y = 0; y < PF_SIZE; y++){
            if(playfield[y][x] == POINT && willi.x == y && willi.y == x){
                willi.boazen += 1;
                playfield[y][x] = SNAKE;
            }else if(playfield[y][x] == POINT){}
            playfield[y][x] = EMPTY;
        }
    }
    playfield[willi.x][willi.y] = SNAKE;

    if(spwanTimer == 5) {
        spwanTimer = 0;
        int x = rand() % PF_SIZE;
        int y = rand() % PF_SIZE;
        playfield[x][y] = POINT;
    }
}

void drawPlayfield() {
    system("clear");
	int x, y;

    for(x = 0; x < PF_SIZE; x++){
        for(y = 0; y < PF_SIZE; y++){
            if(playfield[y][x] == EMPTY){
                printf(" %s", BLANK);
            } else if(playfield[y][x] == SNAKE) {
                printf("-%s", BLANK);
            } else if(playfield[y][x] == POINT) {
                printf("X%s", BLANK);
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));

    //Init playfield

    willi.x = 8;
    willi.y = 8;
    willi.dir = 6;
    willi.boazen = 0;

    resetPlayfield();
    updatePlayfield();
    drawPlayfield();

    int c;

    while((c = getchar()) != 'q') {
        if(c == 'a'){
            if(willi.dir == 6 || willi.dir == 4){
                willi.dir = 8;
            }
            else willi.dir = 4;
        }
        else if(c == 'x'){
            if(willi.dir == 8 || willi.dir == 2)    willi.dir = 6;
            else willi.dir = 2; 
        } else {
           if(willi.dir == 6)   willi.x += 1;
           if(willi.dir == 2)   willi.y += 1;
           if(willi.dir == 4)   willi.x -= 1;
           if(willi.dir == 8)   willi.y -= 1;
        }

        updatePlayfield();
        drawPlayfield();
        spwanTimer++;
        printf("Boazen:\t%d\n", willi.boazen);
    }

	return 0;
}

