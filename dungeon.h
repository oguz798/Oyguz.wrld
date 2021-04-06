#pragma once
#include "rlutil.h"
#include <iostream>
#define FLOOR 0
#define WALL 1
#define SHOP (1 << 1)
#define DUNGEON (1 << 2)
#define FLOOR 0
#define WALL 1
#define MONSTER (1 << 1)
#define BOSS (1 << 2)
#define CHEST (1 << 4)
#include "player.h"
#include "town.h"
#include "battle.h"
#include "boss.h"
#include "Monster.h"
using namespace rlutil;
using namespace std;

	
class Dungeon
{
private:
	int bossCounter;
	int monsterCounter;
	Monster* monster ;
	Boss* boss ;
	int m1=1;
	int b1=1;
	int b2=1;
	int b3=1;
	
public:
	Dungeon();
	~Dungeon();
	void  drawDungeon(Player&);
	int  dungeonWork(Player&);
	void gen(Player&);
	
};
