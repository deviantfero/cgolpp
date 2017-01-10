namespace rules {

	std::vector<int> check_neighbours(std::vector< std::vector<LifeForm> > bugs, int x, int y) {
		std::vector<int> result = {0, 0, 0};

		for(int i = -1; i < 2 ; i++){
			for(int j = -1; j < 2; j++){
				//don't check thyself
				if((x + i < 0 || y + j < 0) ||
					(x + i > bugs.size() - 1 || y + j > bugs[0].size() - 1) || 
					(i == 0 && j == 0)) { 
					continue;
				}

				// clear();
				// mvprintw(0, 20, "pos  - %d,%d", x,y);
				// mvprintw(2, 20, "cne  - %d,%d", i, j); //current neighbour
				// mvprintw(4, 20, "off  - %d,%d", x+i, y+j);
				// mvprintw(6, 20, "size - %d,%d", bugs.size(),bugs[0].size());
				// refresh();

				if(bugs[x + i][y + j].is_alive()){
					result[0] += 1;
				} else if(result[0] == 3){
					result[1] = x + i;
					result[2] = y + j;
				}
			}
		}

		return result;
	}


	void play_cgol(std::vector< std::vector<LifeForm> >* bugs_ptr) {
		std::vector<int> result{2,0,0}; //counts neighbours and gives cordinate for birth

		for (int i = 0; i < bugs_ptr->size(); i++) {
			for (int j = 0; j < (*bugs_ptr)[i].size(); j++) {
				if((*bugs_ptr)[i][j].is_alive())
					result = check_neighbours((*bugs_ptr), i, j);
				switch(result[0]) {
					case 0:
					case 1:
						(*bugs_ptr)[i][j].kill();
						break;
					case 2:
						break;
					case 3:
						if(!(*bugs_ptr)[result[1]][result[2]].is_alive())
							(*bugs_ptr)[result[1]][result[2]].birth();
						break;
					default:
						(*bugs_ptr)[i][j].kill();
						break;
				}
			}
		}
	}

}
