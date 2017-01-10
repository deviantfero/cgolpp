#include "./LifeFrom.h"

LifeForm::LifeForm(int x, int y, const char *avatar) {
	this->alive  = false;
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

void LifeForm::birth() {
	this->alive = true;
}

void LifeForm::kill() {
	this->alive = false;
}

bool LifeForm::is_alive() {
	return this->alive;
}
