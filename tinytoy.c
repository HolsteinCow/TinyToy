#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <ncurses.h>
#include "ui.h"
#include "display.h"
//#include "tetris.h"

#define ENABLE_FRAME_PAUSE true
#define DISABLE_FRAME_PAUSE false

int main(int argc, char **argv){
	if(argc == 1){
		return ui_loop(active_m_init, matrix_effect_cycle, ENABLE_FRAME_PAUSE);	
	}
	else{
		char c = 'q';
		if(argv[1][0] == '-'){
			c = argv[1][1];
		}
		switch(c){
			//case 't':
				//return ui_loop(tetris_init, tetris_gameloop, DISABLE_FRAME_PAUSE);
			case 'u':
				return ui_loop(active_m_init, urand_effect_cycle, ENABLE_FRAME_PAUSE);
			case 'h':
				printf("TinyToy --- TinyToy v0.0.1c\n\nUsage: tinytoy [argument]\nNOTE: tinytoy only takes one argument\n\nArguments:\n\t\"no args\"\t\tMatrix effect\n\t-t\t\t\tTetris\n\t-h\t\t\tPrint help menu\n\t-u\t\t\turandom effect\n\nKeybinds:\n\tp\t\t\tPause screen (for matrix)\n\to\t\t\tFrame mode (press o again to return to normal mode)\n");
				return EXIT_SUCCESS;
			default:
				fprintf(stderr, "Error: Use \"tinytoy -h\" for help");
				return EXIT_FAILURE;
		}
	}
}
