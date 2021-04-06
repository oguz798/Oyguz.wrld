#include "Player.h"
using namespace std;
using namespace rlutil;
Player::Player() {
	alive = true;
	level = 1;
	hp = 0;
	armor = 0;
	dps = 0;
	potions = 5;
	key = 3;
	gold = 200;
	
}
bool Player::isAlive() {
	if (hp <= 0)
		return false;
	else
		return true;
}
void Player::setHp(int hp) {
	this->hp = hp;
}
int Player::getHp() {
	return hp;
}
void Player::setDps(int dps) {
	this->dps = dps;
}
int Player::getDps() {
	return dps;
}
void Player::setArmor(int armor) {
	this->armor = armor;
}
int Player::getArmor() {
	return armor;
}
void Player::setGold(int gold) {
	this->gold = gold;
}
int Player::getGold() {
	return gold;
}
void Player::setKey(int key) {
	this->key = key;
}
int Player::getKey() {
	return key;
}
void Player::setPotions(int potions){
	this->potions = potions;
}
int Player::getPotions() {
	return potions;
}
void Player::setRace(string race) {
	this->race = race;
}
string Player::getRace() {
	return race;
}
void Player::setLevel(int level){
	this->level = level;
}
int Player::getLevel(){
	return level;
}
