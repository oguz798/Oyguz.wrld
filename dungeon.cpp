#include "Dungeon.h"
#include "Player.h"
#include <vector>
#define SIZE 10
#define SHOP (1 << 1)
#define DUNGEON (1 << 2)
#define FLOOR 0
#define WALL 1
#define MONSTER (1 << 1)
#define BOSS (1 << 2)
#define CHEST (1 << 4)
#define EXIT (1 << 3)
using namespace rlutil;
using namespace std;
int mapd[SIZE + 20][SIZE];
int xd = (SIZE + 20) / 2 + 1, yd = SIZE / 2 + 1;

Dungeon::Dungeon() {
	bossCounter = 0;
	monsterCounter = 0;
}
void Dungeon::gen(Player& player) {

 	int level = player.getLevel();//dungeon level
	for (int i = 0; i < SIZE + 30; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 || i == SIZE + 29 || j == 0 || j == SIZE-1 )
				mapd[i][j] = WALL;//gen wall
			else if (i == 1 && j == 1) {
				mapd[i][j] = EXIT;//to the town
			}
			else if (rand() % 100/level == 0) {//increases by level
				
				mapd[i][j] = MONSTER;
				monsterCounter++;//when monster is generated increase by one
			}
			else if (rand() % 200/level   == 1) {
				bossCounter++;
				mapd[i][j] = BOSS;//same as monster
			}
			else if (rand() % 200 == 5)
				mapd[i][j] = CHEST;
			
			else
				mapd[i][j] = FLOOR;
		}
	}
	
}
void Dungeon::drawDungeon(Player& player) {
	locate(1,SIZE+ 1);
	setColor(YELLOW);
	cout << "         DUNGEON         "<< endl;
	setColor(LIGHTBLUE);
	cout<< " '<' to exit, $ for chest, red o for monster, blue O for boss, p for potion(+500hp)"<<endl;
	setColor(MAGENTA);
	cout << "LEVEL " << player.getLevel() << endl;
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
					for (int i = 0; i < SIZE + 30; i++) {
					    if (mapd[i][j] == FLOOR) { setColor(BLUE); cout<<"."; }
						else if (mapd[i][j] == WALL) { setColor(MAGENTA); cout<<"#"; }
						else if (mapd[i][j] == MONSTER) { setColor(RED); cout<<"o"; }
						else if (mapd[i][j] == BOSS) { setColor(LIGHTBLUE); cout<<"O"; }
						else if (mapd[i][j] == CHEST) { setColor(WHITE); cout<<"$"; }
						else if (mapd[i][j] == EXIT){	setColor(CYAN); cout << "<";  }
					}
				printf("\n");
				}
				locate(xd + 1, yd + 1);
				setColor(WHITE);
				printf("@");
}
int Dungeon::dungeonWork(Player& player) {

	cls();
	gen(player);
	int oldHp = player.getHp();
	int oldArmor = player.getArmor();
	int oldDps = player.getDps();
	int oldKey = player.getKey();
	int oldPotion = player.getPotions();
	Battle battle;
	Monster* monster = new Monster[monsterCounter];//creates object (length is created amount of monster)
	Boss* boss = new Boss[bossCounter];//creates object (length is created amount of boss)
	setColor(2);
	cout << "          Why is this place so dark????"<<endl;
	Sleep(1000);
	cout << "WELCOME TO THE DUNGEON! HIT ENTER TO RESUME";
	char d = getkey();
	cls();
	if (d != KEY_ENTER)
	{
		Town::townWork(player);//get back to town
	}
	else if (d == KEY_ENTER) {
		hidecursor();
		drawDungeon(player);;

		while (1) {
			if (kbhit()) {

				char k = getkey();
				int oldx = xd;
				int oldy = yd;
				if (k == 'a' || k == 'A') { --xd; }
				else if (k == 'd' || k == 'D') { ++xd; }
				else if (k == 'w' || k == 'W') { --yd; }
				else if (k == 's' || k == 'S') { ++yd; }
				else if (k == KEY_ESCAPE)
					break;

				char t;
				//cant walk tru the wall
				if (mapd[xd][yd] == WALL)
				{
					xd = oldx; yd = oldy;
				}

				else if (mapd[xd][yd] == FLOOR)
				{
					drawDungeon(player);
				}

				if(k=='p')
							{
							 battle.usePotions(player);	
							}
				//exit
				else if (mapd[xd][yd] == EXIT) {
					cls();
					cout << "ARE YOU SURE YOU WANT TO EXIT? YOUR PROGRESS WILL BE LOST!";//first dps hp and armor will be set
					t = getkey();
					cls();
					if (t == KEY_ENTER)
					{
						player.setDps(oldDps);
						player.setHp(oldHp);
						player.setArmor(oldArmor);
						player.setKey(oldKey);
						player.setPotions(oldPotion);
						Town::townWork(player);
					}
					else {
						cout << "Loading..." << endl;
						Sleep(2000);
						drawDungeon(player);
					}
				}



				//monster
				else if (mapd[xd][yd] == MONSTER) {
					cls();
					cout << "Monster says: You cant banish us from the realm of OGI!" << endl;
					if (player.getLevel()==1 && m1==1 ){
					 	Sleep(2000);
						cout << "thinking to yourself:WAIT...Who is OGI??"<<endl;
						m1=0;
						Sleep(2000);	 
						cout << "You say:" <<endl<<"1.You are killing people. I cant let you stay here!" << endl<<"2.You are not wanted here. Go to another hell pit with that 'OGI'!" << endl;
						cout << "hit 1 or 2" << endl;
						Sleep(2000);
					char lvl1 = getkey();
					if (lvl1=='1')
						cout << "Monster says: Try me then! you cant even pass us you little mortal! LONG LIVE OGI" << endl;
					if (lvl1=='2')
						cout << "Monster says:YOU FOOL!!!!! HOW CAN YOU UNDERESTIMATE US? WE WILL SHOW YOU WHAT ITS LIKE TO BE IN A PIT HELL IN THIS WORLD.LIVE LONG OGI!" << endl;
					}
						cout << "HIT ENTER TO FIGHT!" << endl;
					t = getkey();
					cls();
					if (t == KEY_ENTER) {

						cout << "Player Hp:" << player.getHp() << "                  Monster Hp:" << monster[monsterCounter - 1].getHp() << endl;
						cout << "Player Dps:" << player.getDps() << "                 Monster Dps:" << monster[monsterCounter - 1].getDps() << endl;
						cout << "Player Armor:" << player.getArmor() << "               Monster Armor: 100" << endl;
						cout << "Player Potions:" << player.getPotions() << endl;

						cout << endl;
						cout << "Press A to attack!" << endl;
						cout << "Press P to use potion!" << endl;
						cout << endl;

						string race = player.getRace();
						int flag = 0;
						while (1) {

							d = getkey();
							cls();
							cout << "Player Hp:" << player.getHp() << "                  Monster Hp:" << monster[monsterCounter - 1].getHp() << endl;
							cout << "Player Dps:" << player.getDps() << "                 Monster Dps:" << monster[monsterCounter - 1].getDps() << endl;
							cout << "Player Armor:" << player.getArmor() << "               Monster Armor: 100" << endl;
							cout << "Player Potions:" << player.getPotions() << endl;
				


							cout << endl;
							cout << "Press A to attack!" << endl;
							cout << "Press P to use potion!" << endl;
								cout << endl;
							if (race == "nord") {

								if (d == 'a') {
									cout << endl << "Player attacks!" << endl;
									Sleep(1000);
									battle.attack(player, monster[monsterCounter - 1], race);//player vs monster
								}
								else if (d == 'p') {
									
									Sleep(1000);
									battle.usePotions(player);//using potion
									cout << "Player used a potion!! (+500 hp)" << endl;
									cout << "Player now has " << player.getHp() << " hp!" << endl;
								}
							}
							else if (player.getRace() == "elf") {
								cout << "Press H to heal yourself!" << endl;
								if (d == 'a') {
									cout << "Player attacks!" << endl;
									Sleep(1000);
									battle.attack(player, monster[monsterCounter - 1], race);
								}
								else if (d == 'p') {
								
									Sleep(1000);
									battle.usePotions(player);
								}
								else if (d == 'h') {
									cout << "Player uses elf special!" << endl;
									battle.elfSpecial(player, monster[monsterCounter - 1]);
								}
							}
							else if (player.getRace() == "orc") {
								cout << "Press S to increase defense! (Only 1 battle!)" << endl;
								Sleep(1000);
								if (d == 'a')
									battle.attack(player, monster[monsterCounter - 1], race);
								else if (d == 'p')
									battle.usePotions(player);
								else if (d == 's') {
									battle.orcDefense(player);
									flag = 1;//orc's armor is increased
								}
							}
							if (monster[monsterCounter - 1].getHp() <= 0) {
								
								if (rand() % 100 <= 50) {
									cout << "you found a potion !"<<endl;//loot
									player.setPotions(player.getPotions()+1);
									
									}
									else if (rand() % 100 <= 30) {
										cout << "you found a key !"<<endl;//loot
										player.setKey(player.getKey() +1);
										
									}

								anykey("Hit any key to continue...\n");
								cout << "Loading..." << endl;
								Sleep(1000);
								cls();
								drawDungeon(player);
								break;

							}
							Sleep(500);
							cout << endl << "Now Monster attacks!" << endl;
							Sleep(1000);
							battle.attack(monster[monsterCounter - 1], player);
							if (player.getHp() <= 0) {
								cout << endl;
								cout << "TRY AGAIN FROM THE SAME LEVEL!";
								anykey("Hit any key to go back to the town!\n");

								player.setDps(oldDps);//reseting stats
								player.setHp(oldHp);
								player.setArmor(oldArmor);
								player.setKey(oldKey);
								player.setPotions(oldPotion);

								cls();
								cout << "Loading..." << endl;
								Sleep(1000);
								Town::townWork(player);

							}
						cout << endl;
								cout << "Press A to attack!" << endl;
								cout << "Press P to use potion!" << endl;
						}
						mapd[xd][yd] ^= MONSTER;
						monsterCounter--;
						if (flag == 1) {
							player.setArmor(player.getArmor() - 200);
						}

					}
				}

				//chest
				else if (mapd[xd][yd] == CHEST) {
					cls();
					cout << "CHEST...HIT ENTER TO OPEN";
					t = getkey();
					cls();
					if (t == KEY_ENTER) {
						if (player.getKey() <= 0) {
							cout << "You have no key! Hit enter to continue:" << endl;
							char q = getkey();
							cls();
							cout << "Loading...";//returns to dungeon
							Sleep(1000);
							if (q == KEY_ENTER) {
								cls();
								drawDungeon(player);
							}

						}

						else {
							player.setKey(player.getKey() - 1);
							cout << "YOU OPENED THE CHEST" << endl;
							cout << "Loading...";
							Sleep(1000);
							cls();
							//loots
							if (rand() % 3 == 0) {
								cout << "In chest there is a weapon! " << endl;
								if (rand() % 100 < 5) {
									cout << "ULTRA RARE ITEM" << endl;
									cout << "This weapon has +100dps!";
									player.setDps(player.getDps() + 100);
								}
								else if (rand() % 100 < 15) {
									cout << "This weapon has +50dps!";
									player.setDps(player.getDps() + 50);
								}
								else if (rand() % 100 < 30) {
									cout << "This weapon has +25dps!";
									player.setDps(player.getDps() + 25);
								}
								else if (rand() % 100 < 99) {
									
									cout << "This weapon has +20dps!";
									player.setDps(player.getDps() + 20);
								}
							}
							else if (rand() % 3 == 1) {
								cout << "In chest there is a armor! " << endl;
								if (rand() % 100 < 5) {
									cout << "ULTRA RARE ITEM" << endl;
									cout << "This armor has +200 armor!";
									player.setArmor(player.getArmor() + 200);
								}
								else if (rand() % 100 < 15) {
									cout << "This armor has +100 armor!";
									player.setArmor(player.getArmor() + 100);
								}
								else if (rand() % 100 < 30) {
									cout << "This armor has +50 armor!";
									player.setArmor(player.getArmor() + 50);
								}
								else if (rand() % 100 < 99) {
									
									cout << "This armor has +20 armor!";
									player.setArmor(player.getArmor() + 20);
								}
							}
							else if (rand() % 3 == 2) {
								cout << "In chest there is a necklace! " << endl;
								if (rand() % 100 < 5) {
									cout << "ULTRA RARE ITEM" << endl;
									cout << "This necklace has +500 hp!";
									player.setHp(player.getHp() + 500);
								}
								else if (rand() % 100 < 15) {
									cout << "This necklace has +400 hp!";
									player.setHp(player.getHp() + 400);
								} 
								else if (rand() % 100 < 30) {
									cout << "This necklace has +300 hp!";
									player.setHp(player.getHp() + 300);
								}
								else if (rand() % 100 < 99) {
									
									cout << "This necklace has +200 hp!";
									player.setHp(player.getHp() + 200);
								}
							}
							else
								cout << "There is no item in this chest!" << endl;

							if (rand() % 100 < 50) {
								cout << "In the chest there is plenty of gold!" << endl;

								if (rand() % 100 < 25) {
									cout << " You have found 200 gold!" << endl;
									player.setGold(player.getGold() + 200);
								}
								else {
									cout << " You have found 50 gold!" << endl;
									player.setGold(player.getGold() + 50);
								}
							}
							else
								cout << "There is no gold in this chest!" << endl;


							cout << "Hit enter to continue:" << endl;
							char q = getkey();
							cls();
							cout << "Loading...";
							Sleep(1000);
							if (q == KEY_ENTER) {
								cls();
								mapd[xd][yd] ^= CHEST;
								drawDungeon(player);
							}
						}
					}


				}
				//BOSS
				else if (mapd[xd][yd] == BOSS) {
					cls();
					cout << "You can kill our minions, but not us!!" << endl;
					cout<< "YOU ENCOUNTERED A BOSS! PRESS ENTER TO FIGHT!"<< endl;
					t = getkey();
					cls();
					if (t == KEY_ENTER) {
						if (monsterCounter != 0) {
							cout << "you cant fight with the bosses yet ! Kill all the monsters first!" << endl;
							anykey("hit any key to continue");
							cls();
							drawDungeon(player);
						}

						else {
							cls();
					if(player.getLevel()==1 && b1==1)
					{
						b1--;
						cout << "Boss says: How dare you resist against the great OGI? Are you that fool?" << endl;
						Sleep(2000);
						cout << "You say: We will see who is the fool one here!" << endl;
						Sleep(2000);
						cls();
					}
					 if(player.getLevel()==2 && b2==1)
					
					{
						b2--;
						cout << "Boss says:HAHAHAHHA! We are stronger than you!" << endl;
						Sleep(2000);
						cout << "You say:hahaha...You are definitely funnier than the other boss...maybe he should learn from you.Oh wait! HE is DEAD!" << endl;
						Sleep(2000);
						cls();
					}
					 if(player.getLevel()==3 && b3==1)
					{
						b3--;
						cout << "Boss says:You are getting closer to ogi arent you... But sadly this is the closest you can get to ogi.I give you a chance to run!" << endl;
						Sleep(2000);
						cout << "You say: We will see...We will see...!" << endl;
						Sleep(2000);
						cls();
					}
							cout << "Player Hp:" << player.getHp() << "                  Boss Hp:" << boss[bossCounter - 1].getHp() << endl;
							cout << "Player Dps:" << player.getDps() << "                 Boss Dps:" << boss[bossCounter - 1].getDps() << endl;
							cout << "Player Armor:" << player.getArmor() << "               Boss Armor: 100" << endl;
							cout << "Player Potions:" << player.getPotions() << endl;

							cout << endl;
							cout << "Press A to attack!" << endl;
							cout << "Press P to use potion!" << endl;
							cout << endl;
							string race = player.getRace();
							int flag = 0;
							while (1) {
								d = getkey();
								cls();
								cout << "Player Hp:" << player.getHp() << "                  Boss Hp:" << boss[bossCounter - 1].getHp() << endl;
								cout << "Player Dps:" << player.getDps() << "                 Boss Dps:" << boss[bossCounter - 1].getDps() << endl;
								cout << "Player Armor:" << player.getArmor() << "               Boss Armor: 100" << endl;
								cout << "Player Potions:" << player.getPotions() << endl;



								cout << endl;
								cout << "Press A to attack!" << endl;
								cout << "Press P to use potion!" << endl;
									cout << endl;
								if (race == "nord") {
									
									if (d == 'a'){
									
									cout << "Player attacks!" << endl;
										Sleep(500);
										battle.attack(player, boss[bossCounter - 1], race);}
									else if (d == 'p'){
									
										Sleep(500);
										battle.usePotions(player);
									}	
								}
								else if (player.getRace() == "elf") {
									cout << "Press H to heal yourself!" << endl;
									
									if (d == 'a'){
									
									Sleep(500);
										cout << "player attacks!" << endl;
										battle.attack(player, boss[bossCounter - 1], race);}
									else if (d == 'p'){
									
									Sleep(500);
										battle.usePotions(player);}
									else if (d == 'h')
									Sleep(500);
										battle.elfSpecial(player, boss[bossCounter - 1]);
								}
								else if (player.getRace() == "orc") {
									cout << "Press S to increase defense! (Only 1 battle!)" << endl;
									
									if (d == 'a'){
									
										cout << "Player attacks!" << endl;
										Sleep(1000);
										battle.attack(player, boss[bossCounter - 1], race);}
									else if (d == 'p'){
								
										Sleep(1000);
										battle.usePotions(player);}
									else if (d == 's') {
										Sleep(1000);
										battle.orcDefense(player);
										flag = 1;
									}
									cout << endl;
								}
								if (boss[bossCounter - 1].getHp() <= 0) {
									
									if (rand() % 100 <= 50) {
										Sleep(500);
									cout << "you found 2 potions !"<<endl;
									player.setPotions(player.getPotions()+2);
									
									}
									else if (rand() % 100 <= 30) {
										Sleep(500);
										cout << "you found 2 keys !"<<endl;
										player.setKey(player.getKey() +2);
										
									}
								    
									Sleep(500);
									cout << "hit enter to continue:" << endl;
									char q = getkey();
									if (q == KEY_ENTER) {
										cls();
										drawDungeon(player);
										break;

									}


								}
								Sleep(1000);
								cout << endl;
			
								battle.attack(boss[bossCounter - 1], player);
								if (player.getHp() <= 0) {
									cout << endl;
									cout << "TRY AGAIN FROM THE SAME LEVEL!";
									anykey("hit any key to go back to the town!");

									player.setDps(oldDps);
									player.setHp(oldHp);
									player.setArmor(oldArmor);
									player.setKey(oldKey);
									player.setPotions(oldPotion);

									cls();
									Town::townWork(player);
								}
							cout << endl;
								cout << "Press A to attack!" << endl;
								cout << "Press P to use potion!" << endl;
							}
							mapd[xd][yd] ^= BOSS;
							bossCounter--;
							if (flag == 1) {
								player.setArmor(player.getArmor() - 200);
							}
						}
					}
				}
			}

			if (monsterCounter == 0 && bossCounter == 0)
			{
				cls();
				cout << "Level " << player.getLevel() << " is over! get ready for the next level!" << endl;
				player.setLevel(player.getLevel() + 1);//this level is cleared so the dungeon is getting harder!
				anykey("hit any key to get back to the town");
				cls();
				Town::townWork(player);
			}


		}
	}
	delete[] monster;
	delete[] boss;

	return 0;
}
Dungeon::~Dungeon(){}
	
