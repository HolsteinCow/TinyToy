#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "ui.h"

WINDOW *uiwindow = NULL;

bool init_ui(){
    uiwindow = initscr();

    for(int x = 0; x < X_BOUND; x++){
		for(int y = 0; y < Y_BOUND; y++){
	 		matrix[x][y].char_val = 0;
			matrix[x][y].brightness = 0;
		}
    }

    if(has_colors() == false){
		endwin();
		fprintf(stderr, "Your terminal does not support colors!\n");
		return false;
    }
    start_colors();

    return true;
}

void teardown_ui(){
    delwin(uiwindow);
    endwin();
    refresh();
}

void update_ui(){
	for(int x = 0; i < X_BOUND; x++){
		for(int y = 0; i < Y_BOUND; y++){
			int brightness = matrix[x][y].brightness;
		}
	}
}
