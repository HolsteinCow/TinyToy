#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"
#include "display.h"
/*
#define MATRIX_RANDOM_SPAWN_LINE_PROB 0.75
#define M_CHARACTER 'X'
#define LINES 250

typedef struct{
	char r_char;
	int x, y, brightness;
	bool alive;
}line;

attr matrix[X_BOUND][Y_BOUND];
line active[LINES];

void active_m_init(){
	time_t t;
	srand((unsigned)time(&t));
	for(int i = 0; i < LINES; i++){
		active[i].alive = false;
	}
}

double gen_rand(){
	return (double)rand() / (double)RAND_MAX;
}

char gen_char(){
	//returns random ascii character from range 33 to 126
	return 33 + (rand() % 93);
}

void gen_line(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive == false){
			active[i].alive = true;
			active[i].x = rand() % X_BOUND;
			active[i].y = 0;
			active[i].brightness = MAX_BRIGHTNESS;
			active[i].r_char = gen_char();
			return;
		}
	}
}

void buffer_display(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive){
			matrix[active[i].x][active[i].y].char_val = active[i].r_char;
			matrix[active[i].x][active[i].y].brightness = active[i].brightness;
		}
		if(active[i].y++ >= Y_BOUND - 1){
			active[i].alive = false;
		}
	}
}

void update_logic(){

}

void display_cycle(){
	if(gen_rand() < MATRIX_RANDOM_SPAWN_LINE_PROB){
		gen_line();
	}
	buffer_display();
	update_logic();
}*/
attr matrix[X_BOUND][Y_BOUND];

void display_cycle(){
	for(int y = 0; y < Y_BOUND; y++){
		matrix[6][y].char_val = 'x';
		matrix[6][y].brightness =  31;
	}
}
