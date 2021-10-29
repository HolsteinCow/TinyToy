#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "ui.h"

WINDOW *uiwindow = NULL;

bool init_ui(){
    uiwindow = initscr();

    for(int x = 0; x < X_BOUND; x++){
	for(int y = 0; y < Y_BOUND; y++){
	    
	}
    }

    if(has_colors() == false){
	endwin();
	fprintf(stderr, "Your terminal does not support colors!");
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
