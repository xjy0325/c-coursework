/* Title: Balls and their admirers
 * Author: Gökçe Aydos(85%) and Xingjia Yu(15%)
 * Description: build a graphical simulation with lots of moving balls,
where they randomly follow each other and end up at the same position.
 */

#include "../raylib/include/raylib.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define WIDTH 400
#define HEIGHT 400
#define TITLE "Balls and their admirers"
#define BALL_COUNT 100
#define FPS 60
#define VEL_MAX 5
#define RADIUS_MAX 20
#define RADIUS_MIN 5

// create a color pool with array and predefined struct Color
Color COLORS[] = {
    LIGHTGRAY, GRAY,   DARKGRAY, YELLOW,     GOLD,      ORANGE,  PINK,
    RED,       MAROON, GREEN,    LIME,       DARKGREEN, SKYBLUE, BLUE,
    DARKBLUE,  PURPLE, VIOLET,   DARKPURPLE, BEIGE,     BROWN,   DARKBROWN,
};

// Definition of Ball
// Ball stores state and other properties
typedef struct Ball {
  int posx;
  int posy;
  int velx;
  int vely;
  int radius;
  Color color;
  struct Ball *follows;
} Ball;

// declare 100 balls with array
Ball balls[BALL_COUNT];

// Initialize a ball with random values
Ball *init_ball_random(Ball *p) {

  // initialize properties of a ball but follows
  p->posx = rand() % WIDTH;
  p->posy = rand() % HEIGHT;
  p->velx = rand() % VEL_MAX;
  p->vely = rand() % VEL_MAX;
  p->radius = rand() % (RADIUS_MAX - RADIUS_MIN) + RADIUS_MAX;
  p->color = COLORS[rand() % 20];

  return p;
}

// Initialize all `balls`
void init_balls_random() {
  // random seed via TIME
  srand(time(NULL));

  // first initialize all balls
  for (size_t i = 0; i < BALL_COUNT; i++) {
    init_ball_random(&balls[i]);
  }

  // when all balls are initialized, and decide the leader ball for each of one
  int BallId;
  for (size_t i = 0; i < BALL_COUNT; i++) {
    do {
      BallId = rand() % BALL_COUNT;
    } while (i == BallId);
    balls[i].follows = &balls[BallId];
  }
}

Ball *draw_ball(Ball *p) {
  DrawCircle(p->posx, p->posy, p->radius, p->color);
  return p;
}

// Updates the positions of balls according to their velocities
Ball *update_pos(Ball *p) {
  p->posx = (WIDTH + p->posx + p->velx) %
            WIDTH; // `WIDTH +` because C uses truncated division
  p->posy = (HEIGHT + p->posy + p->vely) % HEIGHT;
  return p;
}

// Updates the velocity of a ball so that it follows the leading ball
Ball *update_vel_for_following(Ball *p) {
  int errx = p->follows->posx - p->posx;
  int erry = p->follows->posy - p->posy;
  p->velx = errx > 0 ? 1 : -1;
  p->vely = erry > 0 ? 1 : -1;
  return p;
}

// Update all elements
void update_elements() {
  for (size_t i = 0; i < _Countof balls; ++i) {
    draw_ball(update_pos(update_vel_for_following(&balls[i])));
  }
}

int main() {
  InitWindow(WIDTH, HEIGHT, TITLE);
  SetTargetFPS(FPS);

  init_balls_random();

  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();
    update_elements();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
}