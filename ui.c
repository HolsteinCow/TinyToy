#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include "ui.h"

WINDOW *uiwindow = NULL;

int trail[MAX_BRIGHTNESS + 1] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 6};

bool init_ui(){
	uiwindow = initscr();
	noecho();
	cbreak();

	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			matrix[x][y].char_val = '\0';
			//matrix[x][y].brightness = 0;
		}
	}
	
	start_color();
	if(has_colors() == false){
		endwin();
		fprintf(stderr, "Error: your terminal does not support colors!\n");
		return false;
	}

	return true;
}

void teardown_ui(){
	delwin(uiwindow);
	endwin();
	refresh();
}

void update_ui(){
	for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
			//color_set(trail[matrix[x][y].brightness], NULL);
			mvaddch(y, x, matrix[x][y].char_val);
		}
	}
	refresh();
}

/*void set_color(){	
}*/
