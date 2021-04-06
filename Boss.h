#pragma once
#include "rlutil.h"
#include "Monster.h"
using namespace std;
using namespace rlutil;
  class Boss :
	public Monster
{
public:
	Boss();
	int getHp();
	void setHp(int);
	int getDps();
	void setDps(int);
};
