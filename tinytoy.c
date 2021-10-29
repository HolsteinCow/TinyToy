#include <ncurses.h>

int main(void){
	initscr();
	printw("test 123");
	refresh();
	getch();
	endwin();
	return 0;
}
