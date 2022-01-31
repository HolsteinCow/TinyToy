#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"
#include "display.h"

#define MATRIX_RANDOM_SPAWN_LINE_PROB 0.8
#define URAND_HIGHLIGHT_PROB 0.25
#define LINES 250
#define LINES_PER_SPAWN 2

extern attr matrix[X_BOUND][Y_BOUND];
line active[LINES];
rem rem_list[LINES];

void active_m_init(){
	time_t t;
	srand((unsigned)time(&t));

	for(int i = 0; i < LINES; i++){
		active[i].alive = false;
		active[i].x = 0;
		active[i].y = 0;
		rem_list[i].x = 0;
		rem_list[i].tick = 0;
		rem_list[i].on = false;
	}
}

double gen_rand_d(){
	return (double)rand() / (double)RAND_MAX;
}

char gen_char(){
	//returns random ascii character from range 33 to 126
	return 32 + (rand() % 94);
}

void gen_line(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive == false){
			active[i].alive = true;
			active[i].x = rand() % X_BOUND;
			active[i].y = 0;
			active[i].life = 2 + (rand() % 10);
			break;
		}
	}
}

void pack_matrix(){
	for(int i = 0; i < LINES; i++){
		if(active[i].alive){
			matrix[active[i].x][active[i].y].char_val = gen_char();
			matrix[active[i].x][active[i].y].color = true;
			matrix[active[i].x][active[i].y].highlight = true;
		}
		
		if(active[i].y++ >= Y_BOUND - 1){
			active[i].alive = false;
			rem_list[i].on = true;
			rem_list[i].x = active[i].x;
			rem_list[i].tick = active[i].life;
		}
		else if(active[i].y >= active[i].life){
			matrix[active[i].x][active[i].y - (active[i].life)].color = false;
			matrix[active[i].x][active[i].y - (active[i].life)].highlight = false;
		}
		if(rem_list[i].tick == 0){
			rem_list[i].on = false;
			continue;
		}
		if(rem_list[i].on){	
			matrix[rem_list[i].x][Y_BOUND - (rem_list[i].tick)].color = false;
			matrix[rem_list[i].x][Y_BOUND - (rem_list[i].tick)].highlight = false;
			rem_list[i].tick--;
		}
	}
}	

void matrix_effect_cycle(){
	if (gen_rand_d() < MATRIX_RANDOM_SPAWN_LINE_PROB)
		gen_line();
	
	pack_matrix();
}

void urand_effect_cycle(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			matrix[x][y].char_val = gen_char();
			matrix[x][y].color = true;
		}
	}
}
