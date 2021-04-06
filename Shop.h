#pragma once
#include "rlutil.h"
#include "Player.h"
#include "Town.h"
#define FLOOR 0
#define WALL 1
#define WEAPONER (1 << 2)
#define ARMORER (1 << 3)
#define FOODSHOP (1 << 4)
#define TOWN (1 << 5)
#define SIZE 10

using namespace std;
using namespace rlutil;
class Shop
{
public:
	void armorer(Player&);
	void weaponer(Player&);
	void foodshop(Player&);
	void shopWork(Player&);
	Shop();//generate shop
	void drawShop(Player&);
};

