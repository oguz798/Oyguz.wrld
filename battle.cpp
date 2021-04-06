#include "battle.h"

void Battle::attack(Player& player, Monster& monster,string race) {
	int damage;
	int lowDmg = player.getDps() / 4 ;
	if (race == "nord") {
		if (rand() % 100 < 25)
			damage = player.getDps();//if race is nord %25 chance of full damage
		else
		  damage = (rand() % player.getDps())+lowDmg ;//between lowdmg-playerdmg
	}
	else
		damage = (rand() % player.getDps())+lowDmg ;//gets random damage between low and max dmg
	damage = damage * 9 / 10; //armor of monster is 100 so 100/1000 damage decrease
	monster.setHp( monster.getHp()- damage);
	cout<<endl;
	cout << "Player has made " << damage << "to monster!" << endl;
	if (monster.getHp() <= 0) {
		cout<<endl;
 		cout << "THE MONSTER HAS BEEN KILLED!"<<endl;
								 	
		}
	else
	cout << "Now monster has " << monster.getHp() << " hp!" << endl;
}
void Battle::attack(Monster& monster, Player& player) {

	int damage = rand() % monster.getDps() + 10;//between 10-monsterdps
	 
	damage -= player.getArmor() / 1000;
	player.setHp(player.getHp() - damage);
	cout << "Monster has made " << damage << "to Player!" << endl;
	if (player.getHp() <= 0) {
		cout<<endl;
 		cout << "YOU HAVE BEEN KILLED!"<<endl;
								 	
		}
		else
			cout << "Now player has " << player.getHp() << " hp!" << endl;
	}

void Battle::attack(Player& player , Boss& boss,string race) {
	
	int damage;
	int lowDmg = player.getDps() / 4;
	if (race == "nord") { //if race is nord %25 chance of full damage
		if (rand() % 100 < 25)
			damage = player.getDps();
		else
		  damage = (rand() % player.getDps()) + lowDmg;//between lowdmg-playerdmg
	}
	else
	damage = (rand() % player.getDps()) + lowDmg;//between lowdmg-playerdmg
	damage = damage * 90 / 100; //armor of monster is %10

	boss.setHp(boss.getHp() - damage);
	if(damage>player.getDps())
	 cout<< "CRITIC!"<< endl;
	cout << "Player has made " << damage << "to boss!" << endl;
	Sleep(1000);
	if (boss.getHp() <= 0) {
		cout<<endl;
 		cout << "THE BOSS HAS BEEN KILLED!"<<endl;
								 	
		}
	else
	cout << "Now boss has " << boss.getHp() << " hp!" << endl;
}
void Battle::attack(Boss& boss, Player& player) {

	int damage = rand() % boss.getDps() + 100;
	 
	damage -= player.getArmor() / 100;
	player.setHp(player.getHp() - damage);
	cout << "Boss has made " << damage << "to Player!" << endl;
	Sleep(1000);
	if (player.getHp()<0)
			cout<<"YOU HAVE BEEN KILLED!"<<endl;
	else
		cout << "Now Player has " << player.getHp() << " hp!" << endl;
}
void Battle::usePotions(Player& player) {
	
	if (player.getPotions() <= 0)
		cout << "There is no potion!" << endl;
	else {
		player.setHp(player.getHp() + 500);
		player.setPotions(player.getPotions()-1);
	}
		
}
void Battle::elfSpecial(Player& player,Boss& boss) {

	int damage = (rand() % player.getDps()) + 10;
	//damage = damage * 90 / 100; (ignores armor)

	boss.setHp(boss.getHp() - damage);
	player.setHp(player.getHp() + damage);//heals 

	cout << "Player has made " << damage << "to boss!" << endl;
	cout << "Now boss has " << boss.getHp() << " hp!" << endl;
	cout << "Player gained " << damage << " hp! Now player has " << player.getHp() << " hp!" << endl;
}
void Battle::elfSpecial(Player& player, Monster& monster) {

	int damage = (rand() % player.getDps()) + 10;
	//damage = damage * 90 / 100; (ignores armor)

	monster.setHp(monster.getHp() - damage);
	player.setHp(player.getHp() + damage);//heals 
	if(damage>player.getDps())
	 cout<< "CRITIC!"<< endl;
	cout << "Player has made " << damage << " dps to monster!" << endl;
	cout << "Now boss has " << monster.getHp() << " hp!" << endl;
	cout << "Player gained " << damage << " hp! Now player has " << player.getHp() << " hp!" << endl;
}
void Battle::orcDefense(Player& player) {

	player.setArmor(player.getArmor() + 200); //armor increase

	cout << "Player's armor has increased !! (+200 armor)" << endl;
	cout << "Player now has " << player.getArmor() << " armor!" << endl;
}
