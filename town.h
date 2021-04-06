#pragma once
#include <iostream>
#include "rlutil.h"
#include "Player.h"
#include "Shop.h"
#include "Dungeon.h"


using namespace rlutil;
using namespace std;

class Town
{
public:
	void static townWork(Player&);
	Town();
	void static drawTown(Player&);
};

