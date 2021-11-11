#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"

#define BLANK_CHAR 1
#define GREEN_CHAR 2
#define GREEN_HIGHLIGHT 3
#define UI_GREEN 154

WINDOW *uiwindow = NULL;

bool init_ui(){
	uiwindow = initscr();
	noecho();
	cbreak();
	nodelay(uiwindow, TRUE);
	curs_set(0);
	attrset(A_BOLD);

	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			matrix[x][y].char_val = 0;
			matrix[x][y].color = false;
		}
	}
	
	start_color();

	if(has_colors() == false){
		endwin();
		fprintf(stderr, "Error: your terminal does not support colors!\n");
		return false;
	}

	init_pair(BLANK_CHAR, COLOR_BLACK, COLOR_BLACK);
	init_pair(GREEN_CHAR, COLOR_GREEN, COLOR_BLACK);
	init_pair(GREEN_HIGHLIGHT, COLOR_WHITE, UI_GREEN);

	return true;
}

void pause_ui(){
	nodelay(uiwindow, FALSE);
	getch();
	nodelay(uiwindow, TRUE);
}

void teardown_ui(){
	delwin(uiwindow);
	endwin();
}

void update_ui(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			if(matrix[x][y].highlight){
				attron(COLOR_PAIR(GREEN_HIGHLIGHT));
				mvaddch(y, x, matrix[x][y].char_val);
				attroff(COLOR_PAIR(GREEN_HIGHLIGHT));
				matrix[x][y].highlight = false;
				continue;	
			}
			if(matrix[x][y].color){
				attron(COLOR_PAIR(GREEN_CHAR));
				mvaddch(y, x, matrix[x][y].char_val);
				attroff(COLOR_PAIR(GREEN_CHAR));
			}
			else{
				attron(A_INVIS);
				attron(COLOR_PAIR(BLANK_CHAR));
				mvaddch(y, x, matrix[x][y].char_val);
				attroff(COLOR_PAIR(BLANK_CHAR));
				attroff(A_INVIS);
			}
		}
	}
	refresh();
}
