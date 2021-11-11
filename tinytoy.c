#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <ncurses.h>
#include "ui.h"
#include "display.h"

#define TEST_CYCLE 200
#define TICK_DELAY 20000L

int main(int argc, char **argv){
	/*if(argc < 2){
		printf("Usage: %s - ");
		return EXIT_FAILURE;
	}*/

	if(!init_ui()){
		fprintf(stderr ,"Error: init_ui() faliure, ui failed to initialize\n");
		return EXIT_FAILURE;
	}
	active_m_init();

	for(;;){
		display_cycle();
		update_ui();
		char c = getch();
		if(c == 'p'){
			pause_ui();
		}
		else if(c > 0){
			break;
		}
		usleep(TICK_DELAY);
	}

	teardown_ui();
	return EXIT_SUCCESS;
}
