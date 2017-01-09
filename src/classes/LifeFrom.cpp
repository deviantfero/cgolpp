#include "./LifeFrom.h"

LifeForm::LifeForm(int x, int y, const char *avatar) {
	this->alive = false;
	this->posx   = x;
	this->posy   = y;
	this->avatar = avatar;
}

LifeForm::LifeForm() {
	this->alive = false;
}

void LifeForm::set_pos(int x, int y) {
	this->posx = x;
	this->posy = y;
}

void LifeForm::set_avatar(const char *avatar) {
	this->avatar = avatar;
}

void LifeForm::switch_on() {
	if(this->alive)
		this->alive = false;
	else
		this->alive = true;
}

bool LifeForm::is_alive() {
	return this->alive;
}
