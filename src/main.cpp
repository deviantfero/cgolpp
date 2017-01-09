#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <ctime>
#include "./classes/LifeFrom.h"

#define AVTR "*"

std::vector< std::vector<LifeForm> > init_bugs(int, int);

int main( void ) {
	int cols, rows;

	initscr();
	getmaxyx(stdscr, cols, rows);

	std::vector< std::vector<LifeForm> > bugs = init_bugs(cols, rows);
	mvprintw((cols/2), (rows/2), "%d x %d", cols, rows);

	refresh();
	getch();
	endwin();
	return 0;
}

std::vector< std::vector<LifeForm> > init_bugs(int cols, int rows) {
	std::vector< std::vector<LifeForm> > bugs;
	std::srand(std::time(0));
	int random;

	for(int i = 0; i < cols; i++) {
		std::vector<LifeForm> col;
		for (int j = 0; j < rows; j++) {
			random = (std::rand()%200) + 1;
			LifeForm bug(i, j, AVTR);
			col.push_back(bug);

			if(bug.is_alive())
				mvprintw(bug.posx, bug.posy, bug.avatar);
		}
		bugs.push_back(col);
	}

	return bugs;
}
