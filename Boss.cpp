#include "boss.h"
Boss::Boss() {
	hp = 2000;
	dps = 600;
	armor = 300;
}
int Boss::getHp() {
	return hp;
}
void Boss::setHp(int hp) {
	this->hp= hp;
}
int Boss::getDps() {
	return dps;
}
void Boss::setDps(int dps) {
	this->dps= dps;
}
