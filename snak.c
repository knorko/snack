#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PF_SIZE 16
#define EMPTY 0
#define SNAKE 1
#define POINT 2
#define BLANK "   "

//FUCK YOU
//Fuck you selber

int spwanTimer = 0;
int gameover = 0;

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

void updatePlayfield() {
    int x,y;
	
    for(x = 0; x < PF_SIZE; x++) {
        for(y = 0; y < PF_SIZE; y++) {
            if(playfield[y][x] == POINT && willi.x == y && willi.y == x) {
                willi.boazen += 1;
                playfield[y][x] = SNAKE;
            } else if(playfield[y][x] == POINT) {
            	//Do nothing
            } else {
				playfield[y][x] = EMPTY;	
            }
        }
    }
	
    playfield[willi.x][willi.y] = SNAKE;

    if(spwanTimer == 5) {
        spwanTimer = 0;
        int x = rand() % PF_SIZE;
        int y = rand() % PF_SIZE;
        playfield[x][y] = POINT;
    }
	
	spwanTimer++;
}

void drawPlayfield() {
	int x, y;

    for(x = 0; x < PF_SIZE; x++) {
        for(y = 0; y < PF_SIZE; y++) {
            if(playfield[y][x] == EMPTY) {
                printf("o%s", BLANK);
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

    int c;

    do {
		
		if(!gameover) {
			
	        if(c == 'a') {
            
				if(willi.dir == 6 || willi.dir == 4) {
	                willi.dir = 8;
	            } else {
					willi.dir = 4;
				}
			
	        } else if(c == 'x') {
            
				if(willi.dir == 8 || willi.dir == 2) {
					willi.dir = 6;
	            } else {
					willi.dir = 2;
				}
			 
	        } else {
				//Walk
		        if(willi.dir == 6)   willi.x += 1;
		        if(willi.dir == 2)   willi.y += 1;
		        if(willi.dir == 4)   willi.x -= 1;
		        if(willi.dir == 8)   willi.y -= 1;
				
				//check if out of border
				if(willi.x < 0)
					willi.x = 0;
				else if(willi.x >= PF_SIZE)
					willi.x = PF_SIZE - 1;
				
				if(willi.y < 0)
					willi.y = 0;
				else if(willi.y >= PF_SIZE)
					willi.y = PF_SIZE - 1;
				
	        }
			
			
			updatePlayfield();
		}
			
			//not portable on non-unix systems, biatch!
			system("clear");
			
			printf("Boazen:\t%d\n", willi.boazen);
	        drawPlayfield();
			printf("(a:up/left, x:down/right, q:quit) > ");

	} while((c = getchar()) != 'q');
	
	return 0;
}

