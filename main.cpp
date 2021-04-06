#include<iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Boss.h"
#include "Monster.h"
#include "Dungeon.h"
#include "Player.h"
#include "rlutil.h"
#include <string>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
using namespace rlutil;
//ÖYKÜ YATIKKAYA 201811063
//OÐUZCAN BALDEMÝR 201811011
int main() {
	string title="OYGUZ WORLD";
	setConsoleTitle(title);
	hidecursor();
	saveDefaultColor();
	setColor(4);
	cout<<("                   Welcome To the OYGUZ World!                 ")<<endl;
	setColor(6);
	Sleep(1000);
	cout<<"In this game you can go to the dungeon to fight with your enemies and open chests for extra player buffs."<<endl;
	Sleep(1000);
	cout<<"After you kill all the enemies in the dungeon you level up so that your dungeon gets harder as well."<<endl;
	Sleep(1000);
	cout<<"If you need any more buff you can buy extra items from the shop. you can go there from the town."<<endl;
	Sleep(1000);
	cout<<"You need coins to buy extra items.You can find coins from the chests in the dungeon."<<endl;
	Sleep(1000);
	cout<<"Also if you kill monsters or bosses there is a possibility that they drop health potions,keys to open chests."<<endl;
	Sleep(1000);
	setColor(MAGENTA);
	Sleep(1000);
	cout<<endl;
	anykey("Lets see the highest level you can get! Hit any key to start.\n");
	srand(0);
	
	Player player;
	string race;
	setColor(BLUE);
	cout << "Choose which race you want to play with?" << endl;
	setColor(LIGHTBLUE);
	cout<<"(*WRITE* NORD FOR EXTRA DAMAGE IN BATTLE, ORC FOR EXTRA SHIELD AND SHIELD BUFF IN BATTLE AND ELF FOR HEALTH REGENERATION IN BATTLE): "<<endl;
	cin >> race;

	if (race == "elf"||race == "ELF") {
		player.setRace("elf");
		player.setDps(700);//dps is damage
		player.setHp(500);
		player.setArmor(100);
		cout << "Player has been created!" << endl;
	}
	else if (race == "orc" || race == "ORC") {
		player.setRace("orc");
		player.setDps(500);
		player.setHp(1000);
		player.setArmor(400);
		cout << "Player has been created!" << endl;
	}
	else if (race == "nord" || race == "NORD") {
		player.setRace("nord");
		player.setDps(900);
		player.setHp(400);
		player.setArmor(100);
		cout << "Player has been created!" << endl;
		Sleep(2000);
		cls();
	}
		
	
	setColor(6);
	cout<<"Creating town..."<<endl;
	Sleep(2000);
	Town::townWork(player);//static method
	return 0;
}
