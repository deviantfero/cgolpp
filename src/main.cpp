#include <iostream>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include "./classes/LifeFrom.h"
#include "./proc/rules.h"

#define AVTR "o"

std::vector< std::vector<LifeForm> > init_bugs(int, int);
void randomize_life(std::vector< std::vector<LifeForm> >*, int);
void redraw_grid(std::vector< std::vector<LifeForm> >);

int main(int argc, char** argv) {
	int cols, rows;

	initscr();
	curs_set(0); //hides the cursor
	getmaxyx(stdscr, cols, rows);

	std::vector< std::vector<LifeForm> > bugs = init_bugs(cols, rows);
	randomize_life(&bugs, 51);
	for(;;) {
		clear();
		redraw_grid(bugs);
		usleep(10000);
		refresh();
		rules::play_cgol(&bugs);
	}

	endwin();
	return 0;
}

std::vector< std::vector<LifeForm> > init_bugs(int cols, int rows) {
	std::vector< std::vector<LifeForm> > bugs;

	for(int i = 0; i < cols; i++) {
		std::vector<LifeForm> col;
		for (int j = 0; j < rows; j++) {
			LifeForm bug(j, i, AVTR);
			col.push_back(bug);
		}
		bugs.push_back(col);
	}

	return bugs;
}

void randomize_life(std::vector< std::vector<LifeForm> >* bugs_ptr, int density) {
	std::srand(std::time(0)); for(int i = 0; i < (*bugs_ptr).size(); i++) {
		for(int j = 0; j < (*bugs_ptr)[i].size(); j++) {
			if(rand()%density > rand()%100) {
				(*bugs_ptr)[i][j].birth();
			}
		}
	}
}

void redraw_grid(std::vector< std::vector<LifeForm> > bugs) {
	for(auto bug_row : bugs) {
		for(auto bug : bug_row) {
			if(bug.is_alive()) {
				mvprintw(bug.posy, bug.posx, bug.avatar);
			}
		}
	}
}
