#pragma once
#include "rlutil.h"
using namespace std;
using namespace rlutil;
class Monster
{
protected:
	int hp;
	int dps;
	int armor;
	
public:
	Monster();
	int getHp();
	void setHp(int);
	int getDps();
	void setDps(int);
	
};

