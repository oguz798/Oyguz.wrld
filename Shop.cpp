#include "Shop.h"
#define FLOOR 0
#define WALL 1
#define WEAPONER (1 << 2)
#define ARMORER (1 << 3)
#define FOODSHOP (1 << 4)
#define TOWN (1 << 5)
#define SIZE 10
#include "Town.h"
using namespace rlutil;
using namespace std;
int maps[SIZE + 20][SIZE];
int xs = (SIZE + 20) / 2 + 1, ys = SIZE / 2 + 1;

Shop::Shop() {

	for (int i = 0; i < SIZE + 20; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE + 19 || j == 0 || j == SIZE - 1)
				maps[i][j] = WALL;
			else if(i==1)
				maps[i][j] = TOWN;
			else if (i == SIZE + 18)
				maps[i][j] = WEAPONER;
			else if (j == 1)
				maps[i][j] = ARMORER;
			else if (j == SIZE - 2)
				maps[i][j] = FOODSHOP;
			else
				maps[i][j] = FLOOR;
		}
	}
}
void Shop::drawShop(Player& player) {

	locate(1, SIZE + 1);
	setColor(YELLOW);
	cout << "         SHOP         " << endl;
	setColor(WHITE);
	cout << "W for weaponer";
	setColor(CYAN);;
	cout << " A for armorer";
	setColor(YELLOW);
	cout << " F for foodshop";
	setColor(RED);
	cout << " and < for the town" << endl;
	setColor(MAGENTA);
	cout << "LEVEL " << player.getLevel() << endl;
	setColor(YELLOW);
	cout << "Hp:" << player.getHp() << endl;
	setColor(RED);
	cout << "Dps:" << player.getDps() << endl;
	setColor(MAGENTA);
	cout << "Armor:" << player.getArmor() << endl;
	setColor(GREEN);
	cout << "Potions:" << player.getPotions() << endl;
	setColor(YELLOW);
	cout << "Gold:" << player.getGold() << endl;
	setColor(RED);
	cout << "Key:" << player.getKey() << endl;
	locate(1,1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 0; i < SIZE + 20; i++) {
			if (0);

			else if (maps[i][j] == FLOOR) { setColor(BLUE); cout << "."; }
			else if (maps[i][j] == WALL) { setColor(MAGENTA); cout << "#"; }
			else if (maps[i][j] == TOWN) { setColor(RED); cout << "<"; }
			else if (maps[i][j] == WEAPONER) { setColor(WHITE); cout << "W"; }
			else if (maps[i][j] == ARMORER) { setColor(CYAN); cout << "A"; }
			else if (maps[i][j] == FOODSHOP) { setColor(YELLOW); cout << "F"; }
		}
		printf("\n");
	}
	locate(xs + 1, ys + 1);
	setColor(WHITE);
	cout << "@";
}
void Shop::shopWork(Player& player) {
	cls();
	Town town;
	hidecursor();
	saveDefaultColor();
	setColor(2);
	cout << "Welcome to the shop!" << endl;
	setColor(6);
	drawShop(player);
	while (1) {
		
		if (kbhit()) {
			char k = getkey();

			int oldx = xs, oldy = ys;
			if (k == 'a') { --xs; }
			else if (k == 'd') { ++xs; }
			else if (k == 'w') { --ys; }
			else if (k == 's') { ++ys; }
			else if (k == KEY_ESCAPE) break;
			
			if (maps[xs][ys] == WALL) { xs = oldx; ys = oldy; }
			else if (maps[xs][ys] == WEAPONER) {
				cls();
				weaponer(player);
			}
			else if (maps[xs][ys] == ARMORER) {
				cls();
				armorer(player);
			}
			else if (maps[xs][ys] == FOODSHOP) {
				cls();
				foodshop(player);
			}
			//EXIT SHOP
			else if (maps[xs][ys] == TOWN) {
				cls();
				cout << "DO YOU WANT TO LEAVE THE SHOP ? (HIT ENTER TO RESUME)";
				char choice = getkey();
				if (choice == KEY_ENTER) {

					town.townWork(player);
				}
				else {
					cls();
					shopWork(player);
				}
			}
			// Drawing
			drawShop(player);
		}
	}
}
void Shop::armorer(Player& player) {

	cout << "Welcome to do Armorer! (Hit enter to resume)" << endl;

	char d = getkey();
	cls();
	if (d != KEY_ENTER) {
		cls();
		shopWork(player);
	}
	else if (d == KEY_ENTER) {
		cls();
		cout << "1)  +20 Armor (20 gold)" << endl;
		cout << "2)  +50 Armor (50 gold)" << endl;
		cout << "3)  +100 Armor (100 gold)" << endl;
		cout << "What do you want? (hit 1,2,3)" << endl;
        
		int b = getkey();
		cls();
		if (b == '1') {
			if (player.getGold() < 20) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();

				if(q == KEY_ENTER){
					cls();
					drawShop(player);
				}
			}
			else {
				player.setArmor(player.getArmor() + 20);
				player.setGold(player.getGold() - 20);
				cout << "Player now has " << player.getArmor() << " armor!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();

				if(q == KEY_ENTER){

					cls();
					shopWork(player);
				}
				
		}
		}
		else if (b == '2') {
			if (player.getGold() < 50) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();
				if(q == KEY_ENTER){

					cls();
					shopWork(player);
				}
			}
			else {
				player.setArmor(player.getArmor() + 50);
				player.setGold(player.getGold() - 50);
				cout << "Player now has " << player.getArmor() << " armor!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}
				
			}
		
		}
		else if (b == '3') {
			if (player.getGold() < 100) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}		
			}
			else {
				player.setArmor(player.getArmor() + 100);
				player.setGold(player.getGold() - 100);
				cout << "Player now has " << player.getArmor() << " armor!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();

				if(q == KEY_ENTER){
					cls();
					shopWork(player);
				}	
			}
		}
	}
}
void Shop::weaponer(Player& player) {
	cout << "Welcome to do Weaponer! (Hit enter to resume)" << endl;

	char d = getkey();
	if (d != KEY_ENTER) {
		cls();
		shopWork(player);
	}
	else if (d == KEY_ENTER) {
		cout << "1)  +50 Dps (300 gold)" << endl;
		cout << "2)  +100 Dps (550 gold)" << endl;
		cout << "3)  +200 Dps (1000 gold)" << endl;
		cout << "What do you want? (hit 1,2,3)" << endl;

		d = getkey();
		cls();
		if (d == '1') {
			if (player.getGold() < 300) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();
					if(q == KEY_ENTER){
						cls();
				 		shopWork(player);
					}
				
			}
			else {
				player.setDps(player.getDps() + 50);
				player.setGold(player.getGold() - 300);
				cout << "Player now has " << player.getDps() << " dps!" << endl;
				cout << "hit enter to continue:" << endl;
				char q = getkey();
					if(q == KEY_ENTER){
						cls();
				 		shopWork(player);
					}
			}
			
		}
		if (d == '2') {
			if (player.getGold() < 550) {
				cout << "You dont have enough money!"<<endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}	
			}
			else {
				player.setDps(player.getDps() + 100);
				player.setGold(player.getGold() - 550);
				cout << "Player now has " << player.getDps() << " dps!"<<endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}
			}	
		}
		if (d == '3') {
			if (player.getGold() < 1000) {
				cout << "You dont have enough money!"<<endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}	
			}
			else {
				player.setDps(player.getDps() + 200);
				player.setGold(player.getGold() - 1000);
				cout << "Player now has " << player.getDps() << " dps!" << endl;
				cout << "hit enter to leave and any other key to continue" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	shopWork(player);
				}
				else
					weaponer(player);
			}	
		}
	}
}
void Shop::foodshop(Player& player) {
	cout << "Welcome to do Foodshop! (Hit enter to resume)" << endl;

	char d = getkey();
	if (d != KEY_ENTER) {
		cls();
		shopWork(player);
	}
	else if (d == KEY_ENTER) {
		cout << "1.+100 hp (200 gold)" << endl;
		cout << "2.+250 hp (350 gold)" << endl;
		cout << "3.+500 hp (600 gold)" << endl;
		cout << "What do you want? (hit 1,2,3)" << endl;

		d = getkey();
		cls();
		if (d == '1') {
			if (player.getGold() < 200) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}
				
			}
			else {
				player.setHp(player.getHp() + 100);
				player.setGold(player.getGold() - 200);
				cout << "Player now has " << player.getHp() << " hp!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}
			}
			cls();
			shopWork(player);
		}
		if (d == '2') {
			if (player.getGold() < 350) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}		
			}
			else {
				player.setHp(player.getHp() + 250);
				player.setGold(player.getGold() - 350);
				cout << "Player now has " << player.getHp() << " hp!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}
			}
			cls();
			shopWork(player);
		}
		if (d == '3') {
			if (player.getGold() < 600) {
				cout << "You dont have enough money!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}
			}
			else {
				player.setHp(player.getHp() + 500);
				player.setGold(player.getGold() - 600);
				cout << "Player now has " << player.getHp() << " hp!" << endl;
				cout << "hit enter to continue:" << endl;
				char q=getkey();

				if(q == KEY_ENTER){
					cls();
				 	drawShop(player);
				}
			}
			cls();
			shopWork(player);
		}
	}
}
