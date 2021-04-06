#include "Monster.h"
Monster::Monster() {
	hp = 800;
	dps = 400;
	armor = 100;
}
int Monster::getHp() {
	return hp;
}
void Monster::setHp(int hp) {
	this->hp = hp;
}
int Monster::getDps() {
	return dps;
}
void Monster::setDps(int dps) {
	this->dps = dps;
}
