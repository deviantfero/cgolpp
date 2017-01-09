#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <ctime>
#include "./classes/LifeFrom.h"

#define AVTR "*"

std::vector< std::vector<LifeForm> > init_bugs(int, int);
void randomize_life(std::vector< std::vector<LifeForm> >);

int main( void ) {
	int cols, rows;

	initscr();
	getmaxyx(stdscr, cols, rows);

	std::vector< std::vector<LifeForm> > bugs = init_bugs(cols, rows);
	randomize_life(bugs);
	mvprintw((cols/2), (rows/2), "%d x %d", cols, rows);

	refresh();
	getch();
	endwin();
	return 0;
}

std::vector< std::vector<LifeForm> > init_bugs(int cols, int rows) {
	std::vector< std::vector<LifeForm> > bugs;

	for(int i = 0; i < cols; i++) {
		std::vector<LifeForm> col;
		for (int j = 0; j < rows; j++) {
			LifeForm bug(i, j, AVTR);
			col.push_back(bug);
		}
		bugs.push_back(col);
	}

	return bugs;
}

void randomize_life(std::vector< std::vector<LifeForm> > bugs) {
	std::srand(std::time(0));
	for(auto bug_row : bugs) {
		for(auto bug : bug_row) {
			if(rand()%200 > rand()%200){
				bug.birth();
				mvprintw(bug.posx, bug.posy, bug.avatar);
			}
		}
	}
}
