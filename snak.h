#define PF_SIZE 16
#define BLANK "   "
#define MAX_LEN 16*16



enum State{EMPTY, SNAKE, SNACK};
typedef enum State state;

enum Direction{NORTH, EAST, SOUTH, WEST, INIT};
typedef enum Direction direction;

typedef struct{
    int x, y;
    direction dir;
}Point;

typedef struct{
    Point body[MAX_LEN];
    int size;
    int boazen;
}Snake;

void initPlayfield(state[PF_SIZE][PF_SIZE]);
void initSnake(Snake s);
void initSnacks(Point[MAX_LEN]);
Point generateSnack();
void updatePlayfield(Snake, Point[MAX_LEN], state[PF_SIZE][PF_SIZE]);
void updateSnake();
void drawPlayfield(state[PF_SIZE][PF_SIZE]);

