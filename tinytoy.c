#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include "ui.h"
#include "display.h"

#define TEST_CYCLE 1000
#define TICK_DELAY 25000L

void display_loop(){
    init_display();

    for(int i = 0; i < TEST_CYCLE; i++){
		buffer_disp();
		show_disp();
		usleep(TICK_DELAY);
    }
}

int main(int argc, char **argv){
	

    if(!init_ui()){
	fprintf(stderr ,"Error: init_ui() faliure, ui failed to initialize\n");
	return EXIT_FAILURE;
    }
    
    update_ui();

    teardown_ui();
    return EXIT_SUCCESS;
}
