#pragma once
#include "rlutil.h"
#include <string>
using namespace std;
using namespace rlutil;
class Player
{
protected:
	int hp;
	int dps;//damage per second
	int armor;
	int potions;
	int gold;
	bool alive;
	int level;
	int key;
	string race;
public:
	Player();
	string getRace();
	void setRace(string);
	bool isAlive();
	void setHp(int);
	int getHp();
	void setDps(int);
	int getDps();
	void setArmor(int);
	int getArmor();
	void setPotions(int);
	int getPotions();
	void setGold(int);
	int getGold();
	void setKey(int);
	int getKey();
	void setLevel(int);
	int getLevel();
};

