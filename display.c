#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"
#include "display.h"

#define MATRIX_RANDOM_GEN_PROB 0.5
#define MATRIX_RANDOM_DIM_PROB 0.2
#define MATRIX_RANDOM_SPAWN_LINE_PROB 0.7
#define M_CHARACTER 'X'

#define LINES 250

typedef struct{
	int x, y;
	bool alive;
	bool bright;
}line;

attr matrix[X_BOUND][Y_BOUND];
line active[LINES];

double gen_rand();

/*void clear_screen(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			matrix[x][y].char_val = 0;
			matrix[x][y].brightness = 0;
		}
	}
}*/

double gen_rand(){
	time_t t;
	srand((unsigned)time(&t));
	return (double)rand() / (double)RAND_MAX;
}

void active_m_init(){
	for(int i = 0; i < X_BOUND; i++){
		active[i].alive = false;
	}
}

void line_display(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			if(gen_rand() < MATRIX_RANDOM_GEN_PROB){
				matrix[x][y].char_val = M_CHARACTER;
			}
			if(gen_rand() < MATRIX_RANDOM_DIM_PROB){
				if(matrix[x][y].brightness > 0){
					matrix[x][y].brightness--;
				}
			}
		}
	}
}

void gen_line(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive == false){
			active[i].alive = true;
			active[i].x = rand() % X_BOUND;
			active[i].y = 0;
			active[i].bright = rand() % 2;
			return;
		}
	}
}

void update_line(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive){
			if(active[i].bright){
				matrix[active[i].x][active[i].y].brightness = MAX_BRIGHTNESS;
			}
			else{
				matrix[active[i].x][active[i].y].brightness = MIN_BRIGHTNESS;
			}

			if(active[i].y++ >= Y_BOUND - 1){
				active[i].alive = false;
			}
		}
	}
}

void update_display(){
	if(gen_rand() > MATRIX_RANDOM_SPAWN_LINE_PROB){
		gen_line();
	}
	update_line();
	line_display();
}
