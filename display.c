#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"
#include "display.h"

typedef struct{
	int x, y;
	bool alive;
}line;

attr matrix[X_BOUND][Y_BOUND];
line active[X_BOUND];


void clear_screan(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			matrix[x][y].char_val = 0;
			matrix[x][y].brightness = 0;
		}
	}
}

int gen_rand(){
	time_t t;
	srand((unsigned)time(&t));
	return rand() % X_BOUND;
}

void init_display(){
		
}

void active_m_init(){
	for(int i = 0; i < X_BOUND; i++)
		active[i].alive = false;
}

void buffer_display(){
	gen_line();
}

void gen_line(){

}

void show_display(){
	refresh();
}


