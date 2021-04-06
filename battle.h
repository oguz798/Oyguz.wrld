#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "rlutil.h"
#include "Player.h"
#include "Monster.h"
#include "Boss.h"
using namespace rlutil;
using namespace std;
class Battle
{
public:
	void attack(Player&, Monster&,string);
	void attack(Monster&, Player&);
	void attack(Player&, Boss&, string);
	void attack(Boss&,Player&);
	void usePotions(Player&);
	void orcDefense(Player&);//armor increase
	void elfSpecial(Player&,Monster&);//elf attacks and heals himself
	void elfSpecial(Player&, Boss&);

};

