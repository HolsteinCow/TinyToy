#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <ncurses.h>
#include "ui.h"
#include "display.h"

#define TEST_CYCLE 1000
#define TICK_DELAY 50000L

int main(int argc, char **argv){

	if(!init_ui()){
		fprintf(stderr ,"Error: init_ui() faliure, ui failed to initialize\n");
		return EXIT_FAILURE;
	}
	//active_m_init();


	for(int i = 0; i < TEST_CYCLE; i++){
		display_cycle();
		update_ui();
		usleep(TICK_DELAY);
	}

	teardown_ui();
	return EXIT_SUCCESS;
}
