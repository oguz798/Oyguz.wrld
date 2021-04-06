#include "Town.h"
#include "rlutil.h"
#define SIZE 10
#define SHOP (1 << 1)
#define DUNGEON (1 << 2)
#define FLOOR 0
#define WALL 1
#define MONSTER (1 << 1)
#define BOSS (1 << 2)
#define CHEST (1 << 4)
int mapt[SIZE + 20][SIZE];
int xt = (SIZE + 20) / 2 + 1, yt = SIZE / 2 + 1;

Town::Town() {
	
	for (int i = 0; i < SIZE + 20; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE + 19 || j == 0 || j == SIZE - 1)
				mapt[i][j] = WALL;
			else if (i == SIZE + 18)
				mapt[i][j] = SHOP;
			else if (i == 1)
				mapt[i][j] = DUNGEON;
			else
				mapt[i][j] = FLOOR;
		}
	}

}
void Town::drawTown(Player& player) {
	
	Town();
	locate(1,SIZE+ 1);
	setColor(YELLOW);
	cout<< "         TOWN         "<<endl;
	setColor(LIGHTBLUE);
	cout<< "go to white area for dungeon and red area for shop"<<endl;
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
	locate(1, 1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 0; i < SIZE + 20; i++) {
			if (0);

			else if (mapt[i][j] == FLOOR) { setColor(BLUE); cout << "."; }
			else if (mapt[i][j] == WALL) { setColor(MAGENTA); cout << "#"; }
			else if (mapt[i][j] == SHOP) { setColor(RED); cout << "S"; }
			else if (mapt[i][j] == DUNGEON) { setColor(WHITE); cout << "D"; }
		}
		cout<<"\n";
	}
	locate(xt + 1, yt + 1);
	setColor(WHITE);
	cout << "@";
}

void Town::townWork(Player& player)
{
	Shop shop;
	Dungeon dungeon;
	cls();
	hidecursor();
	saveDefaultColor();
	drawTown(player);
	while (1) {
		// Input
		if (kbhit()) {
			char k = getkey();

			int oldx = xt, oldy = yt;
			if (k == 'a' || k == 'A') { --xt; }
			else if (k == 'd'|| k == 'D') { ++xt; }
			else if (k == 'w'|| k == 'W') { --yt; }
			else if (k == 's' || k == 'S') { ++yt; }
			else if (k == KEY_ESCAPE) break;


			if (mapt[xt][yt] == WALL && xt != 5 && xt != 7) { xt = oldx; yt = oldy; }

			else if (mapt[xt][yt] == SHOP) {
				shop.shopWork(player);
			}
			else if (mapt[xt][yt] == DUNGEON) {
				
				dungeon.dungeonWork(player);
				
			}

			drawTown(player);
		}
	}
}
